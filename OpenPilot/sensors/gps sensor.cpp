#include <iostream>
#include <string>
#include <sstream>
#include <vector>
#include <serial.h> // Ensure you have a serial library, like `serial`

class GPSSensor {
public:
    GPSSensor(const std::string& port) : portName(port), serialPort(port) {
        serialPort.setBaudrate(9600);
        serialPort.setPort(portName);
        serialPort.open();
        if (!serialPort.isOpen()) {
            std::cerr << "Error: Could not open GPS port: " << portName << std::endl;
            exit(EXIT_FAILURE);
        }
    }

    ~GPSSensor() {
        if (serialPort.isOpen()) {
            serialPort.close();
        }
    }

    std::vector<double> getLocation() {
        std::string line;
        if (serialPort.available()) {
            line = serialPort.readline();
            return parseGPSData(line);
        } else {
            std::cerr << "Error: No data received from GPS." << std::endl;
            return {};
        }
    }

private:
    std::string portName;
    serial::Serial serialPort;

    std::vector<double> parseGPSData(const std::string& data) {
        std::vector<double> location;
        std::istringstream ss(data);
        std::string token;

        if (std::getline(ss, token, ',')) {
            location.push_back(std::stod(token)); // Latitude
        }
        if (std::getline(ss, token, ',')) {
            location.push_back(std::stod(token)); // Longitude
        }

        return location;
    }
};

// Example usage
extern "C" {
    void load_gps_sensor() {
        GPSSensor gpsSensor("/dev/ttyUSB0"); // Adjust the port as necessary
        while (true) {
            std::vector<double> location = gpsSensor.getLocation();
            if (!location.empty()) {
                std::cout << "Latitude: " << location[0] << ", Longitude: " << location[1] << std::endl;
            }
            std::this_thread::sleep_for(std::chrono::seconds(1)); // Adjust frequency as needed
        }
    }
}
