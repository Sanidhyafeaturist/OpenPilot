#include <iostream>
#include <vector>
#include <string>
#include <cstring>

class LidarSensor {
public:
    LidarSensor(const std::string& port) : portName(port), serialPort(port) {
        serialPort.setBaudrate(115200); // Typical baud rate for LiDAR
        serialPort.setPort(portName);
        serialPort.open();
        if (!serialPort.isOpen()) {
            std::cerr << "Error: Could not open LiDAR port: " << portName << std::endl;
            exit(EXIT_FAILURE);
        }
    }

    ~LidarSensor() {
        if (serialPort.isOpen()) {
            serialPort.close();
        }
    }

    std::vector<double> getDistanceMeasurements() {
        std::string line;
        if (serialPort.available()) {
            line = serialPort.readline();
            return parseLidarData(line);
        } else {
            std::cerr << "Error: No data received from LiDAR." << std::endl;
            return {};
        }
    }

private:
    std::string portName;
    serial::Serial serialPort;

    std::vector<double> parseLidarData(const std::string& data) {
        std::vector<double> distances;
        std::istringstream ss(data);
        std::string token;

        while (std::getline(ss, token, ',')) {
            distances.push_back(std::stod(token)); // Convert each token to double
        }

        return distances;
    }
};

// Example usage
extern "C" {
    void load_lidar_sensor() {
        LidarSensor lidarSensor("/dev/ttyUSB0"); // Adjust the port as necessary
        while (true) {
            std::vector<double> distances = lidarSensor.getDistanceMeasurements();
            if (!distances.empty()) {
                std::cout << "Distance Measurements: ";
                for (const double& distance : distances) {
                    std::cout << distance << " ";
                }
                std::cout << std::endl;
            }
            std::this_thread::sleep_for(std::chrono::milliseconds(100)); // Adjust frequency as needed
        }
    }
}
