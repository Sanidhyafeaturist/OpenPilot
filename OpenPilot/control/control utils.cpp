#include "control_utils.h"
#include <iostream>

float constrain(float value, float min, float max) {
    if (value < min) return min;
    if (value > max) return max;
    return value;
}

void logControlData(float throttle, float steering, float altitude) {
    std::cout << "Control Data - Throttle: " << throttle 
              << ", Steering: " << steering 
              << ", Altitude: " << altitude << std::endl;
}
