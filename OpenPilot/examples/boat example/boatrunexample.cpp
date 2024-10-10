#include <iostream>
#include <vector>
#include <fstream>
#include <yaml-cpp>
#include "gps_navigation.h"
#include "navigation/waypoint_follower.h"
#include "navigation/navigation_utils.h"

struct Waypoint {
    std::string name;
    float latitude;
    float longitude;
};

struct BoatConfig {
    std::string name;
    std::string type;
    std::vector<Waypoint> waypoints;

    void load(const std::string& filename) {
        YAML::Node config = YAML::LoadFile(filename);
        name = config["boat"]["name"].as<std::string>();
        type = config["boat"]["type"].as<std::string>();

        for (const auto& wp : config["navigation"]["waypoints"]) {
            waypoints.push_back({
                wp["name"].as<std::string>(),
                wp["latitude"].as<float>(),
                wp["longitude"].as<float>()
            });
        }
    }
};

int main() {
    // Load configuration
    BoatConfig config;
    config.load("boat_config.yaml");

    // Initialize GPS Navigation
    GPSNavigation gps;
    // For demonstration, setting initial GPS position to the first waypoint
    if (!config.waypoints.empty()) {
        gps.updatePosition(config.waypoints[0].latitude, config.waypoints[0].longitude);
    }

    // Initialize Waypoint Follower
    WaypointFollower follower;
    follower.setWaypoints(config.waypoints);

    // Main loop for navigation
    while (true) {
        // Update GPS position (replace this with actual GPS readings in a real scenario)
        float currentLat, currentLon;
        gps.getCurrentPosition(currentLat, currentLon);

        // Follow waypoints
        follower.followWaypoints();

        // Check if all waypoints have been reached
        if (follower.allWaypointsReached()) {
            std::cout << "All waypoints have been successfully reached." << std::endl;
            break; // Exit the loop if all waypoints are reached
        }

     
    }

    return 0;
}
