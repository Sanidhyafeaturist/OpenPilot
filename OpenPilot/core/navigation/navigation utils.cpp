#include "navigation_utils.h"
#include <cmath>
#include <iostream>

const float EARTH_RADIUS = 6371.0; // Earth's radius in kilometers

float calculateDistance(float lat1, float lon1, float lat2, float lon2) {
    // Convert degrees to radians
    float lat1Rad = lat1 * M_PI / 180.0;
    float lon1Rad = lon1 * M_PI / 180.0;
    float lat2Rad = lat2 * M_PI / 180.0;
    float lon2Rad = lon2 * M_PI / 180.0;

    // Haversine formula
    float dlat = lat2Rad - lat1Rad;
    float dlon = lon2Rad - lon1Rad;

    float a = std::sin(dlat / 2) * std::sin(dlat / 2) +
              std::cos(lat1Rad) * std::cos(lat2Rad) *
              std::sin(dlon / 2) * std::sin(dlon / 2);
    float c = 2 * std::atan2(std::sqrt(a), std::sqrt(1 - a));

    return EARTH_RADIUS * c; // Distance in kilometers
}

void printWaypoint(const Waypoint& waypoint) {
    std::cout << "Waypoint: " << waypoint.name 
              << " | LAT: " << waypoint.latitude 
              << " | LON: " << waypoint.longitude << std::endl;
}
