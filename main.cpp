#include <iostream>
#include <thread>
#include <vector>
#include "OpenPilot/sensors/gps sensor.cpp"   // Include GPS sensor implementation
#include "OpenPilot/sensors/lidar sensor.cpp" // Include LiDAR sensor implementation
#include "OpenPilot/sensors/camera sensor.cpp" // Include Camera sensor implementation

void runGPSSensor() {
    GPSSensor gpsSensor("/dev/ttyUSB0"); // Adjust the port as necessary
    while (true) {
        std::vector<double> location = gpsSensor.getLocation();
        if (!location.empty()) {
            std::cout << "GPS - Latitude: " << location[0] << ", Longitude: " << location[1] << std::endl;
        }
        std::this_thread::sleep_for(std::chrono::seconds(1)); // Adjust frequency as needed
    }
}

void runLidarSensor() {
    LidarSensor lidarSensor("/dev/ttyUSB1"); // Adjust the port as necessary
    while (true) {
        std::vector<double> distances = lidarSensor.getDistanceMeasurements();
        if (!distances.empty()) {
            std::cout << "LiDAR - Distances: ";
            for (const double& distance : distances) {
                std::cout << distance << " ";
            }
            std::cout << std::endl;
        }
        std::this_thread::sleep_for(std::chrono::milliseconds(100)); // Adjust frequency as needed
    }
}

void runCameraSensor() {
    load_camera_sensor(); // Assuming camera sensor code has a function to load and process images
}

int main() {
    std::thread gpsThread(runGPSSensor);
    std::thread lidarThread(runLidarSensor);
    std::thread cameraThread(runCameraSensor);

    gpsThread.join();
    lidarThread.join();
    cameraThread.join();

    return 0;
}
