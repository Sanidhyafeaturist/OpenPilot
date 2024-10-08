#include <iostream>
#include <fstream>
#include <yaml-cpp> // Ensure you have yaml-cpp library installed

class ConfigReader {
public:
    ConfigReader(const std::string& configFile) {
        loadConfig(configFile);
    }

    double getDouble(const std::string& key) const {
        return config[key].as<double>();
    }

    int getInt(const std::string& key) const {
        return config[key].as<int>();
    }

    std::string getString(const std::string& key) const {
        return config[key].as<std::string>();
    }

    std::vector<double> getDoubleArray(const std::string& key) const {
        return config[key].as<std::vector<double>>();
    }

private:
    YAML::Node config;

    void loadConfig(const std::string& configFile) {
        try {
            config = YAML::LoadFile(configFile);
        } catch (const std::exception& e) {
            std::cerr << "Error loading config file: " << e.what() << std::endl;
            exit(EXIT_FAILURE);
        }
    }
};

// Example usage
extern "C" {
    void load_configuration() {
        ConfigReader configReader("config.yaml"); // Adjust the config file path as necessary

        double latitude = configReader.getDouble("gps.latitude");
        double longitude = configReader.getDouble("gps.longitude");
        int lidarBaudRate = configReader.getInt("lidar.baudrate");

        std::cout << "GPS Latitude: " << latitude << ", Longitude: " << longitude << std::endl;
        std::cout << "LiDAR Baud Rate: " << lidarBaudRate << std::endl;
    }
}
