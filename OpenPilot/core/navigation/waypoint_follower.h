#ifndef WAYPOINT_FOLLOWER_H
#define WAYPOINT_FOLLOWER_H

#include <vector>
#include "waypoint.h"

class WaypointFollower {
public:
    WaypointFollower();
    void setWaypoints(const std::vector<Waypoint>& waypoints);
    void followWaypoints();

private:
    std::vector<Waypoint> waypoints;
    size_t currentWaypointIndex;

    bool reachedWaypoint(const Waypoint& waypoint);
};

#endif // WAYPOINT_FOLLOWER_H
