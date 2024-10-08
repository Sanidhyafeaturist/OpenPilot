#include "gps_navigation.h"
#include <iostream>

GPSNavigation::GPSNavigation() : currentLatitude(0), currentLongitude(0) {}

void GPSNavigation::updatePosition(float latitude, float longitude) {
    currentLatitude = latitude;
    currentLongitude = longitude;
    std::cout << "Updated position to LAT: " << currentLatitude << ", LON: " << currentLongitude << std::endl;
}

void GPSNavigation::getCurrentPosition(float& latitude, float& longitude) {
    latitude = currentLatitude;
    longitude = currentLongitude;
}
