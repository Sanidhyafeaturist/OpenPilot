#include "waypoint_follower.h"
#include <iostream>

WaypointFollower::WaypointFollower() : currentWaypointIndex(0) {}

void WaypointFollower::setWaypoints(const std::vector<Waypoint>& waypoints) {
    this->waypoints = waypoints;
}

void WaypointFollower::followWaypoints() {
    if (currentWaypointIndex < waypoints.size()) {
        Waypoint currentWaypoint = waypoints[currentWaypointIndex];
        std::cout << "Following waypoint: " << currentWaypoint.name 
                  << " at LAT: " << currentWaypoint.latitude 
                  << ", LON: " << currentWaypoint.longitude << std::endl;

        // Implement logic to check if the current waypoint is reached
        if (reachedWaypoint(currentWaypoint)) {
            std::cout << "Reached waypoint: " << currentWaypoint.name << std::endl;
            currentWaypointIndex++;
        }
    } else {
        std::cout << "All waypoints followed." << std::endl;
    }
}

bool WaypointFollower::reachedWaypoint(const Waypoint& waypoint) {
    // Placeholder for actual waypoint reach logic
    return true;
}
