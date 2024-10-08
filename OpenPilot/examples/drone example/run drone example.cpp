#include <iostream>
#include <vector>
#include <yaml-cpp>
#include "Core/navigation/gps_navigation.h"
#include "Core/navigation/waypoint_follower.h"
#include "Core/navigation/navigation_utils.h"

struct Waypoint {
    std::string name;
    float latitude;
    float longitude;
    float altitude;
};

struct DroneConfig {
    std::string name;
    std::string type;
    std::vector<Waypoint> waypoints;

    void load(const std::string& filename) {
        YAML::Node config = YAML::LoadFile(filename);
        name = config["drone"]["name"].as<std::string>();
        type = config["drone"]["type"].as<std::string>();

        for (const auto& wp : config["navigation"]["waypoints"]) {
            waypoints.push_back({
                wp["name"].as<std::string>(),
                wp["latitude"].as<float>(),
                wp["longitude"].as<float>(),
                wp["altitude"].as<float>()
            });
        }
    }
};

int main() {
    // Load configuration
    DroneConfig config;
    config.load("drone_config.yaml");

    // Initialize GPS Navigation
    GPSNavigation gps;
    gps.updatePosition(config.waypoints[0].latitude, config.waypoints[0].longitude, config.waypoints[0].altitude);

    // Initialize Waypoint Follower
    WaypointFollower follower;
    follower.setWaypoints(config.waypoints);

    // Main loop for navigation
    while (true) {
        float currentLat, currentLon, currentAlt;
        gps.getCurrentPosition(currentLat, currentLon, currentAlt);

        follower.followWaypoints();

        if (follower.allWaypointsReached()) {
            std::cout << "All waypoints have been successfully reached." << std::endl;
            break;
        }
    }

    return 0;
}
