#ifndef OPENPILOT_H
#define OPENPILOT_H

#include <iostream>

// Communication Module
namespace communication {
    void initialize();
    void sendData(const std::string& data);
    std::string receiveData();
}

// Control Module
namespace control {
    void start();
    void stop();
    void setParameter(int parameter);
}

// Core Module
namespace core {
    void initialize();
    void run();
    void shutdown();
}

// Utility Functions
namespace utils {
    void log(const std::string& message);
    int calculateChecksum(const std::string& data);
}

// Sensor Module
namespace sensors {
    void initialize();
    float readTemperature();
    float readPressure();
}

// Startup Module
namespace startup {
    void runStartupSequence();
}

#endif 
