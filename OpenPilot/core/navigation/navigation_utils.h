#ifndef NAVIGATION_UTILS_H
#define NAVIGATION_UTILS_H

#include "waypoint_follower.h"

float calculateDistance(float lat1, float lon1, float lat2, float lon2);
void printWaypoint(const Waypoint& waypoint);

#endif // NAVIGATION_UTILS_H
