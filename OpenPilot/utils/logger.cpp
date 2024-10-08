#include <iostream>
#include <fstream>
#include <string>
#include <ctime>
#include <mutex>

class Logger {
public:
    Logger(const std::string& logFile) : logFileName(logFile) {
        logStream.open(logFileName, std::ios::app);
        if (!logStream.is_open()) {
            std::cerr << "Error: Could not open log file: " << logFileName << std::endl;
            exit(EXIT_FAILURE);
        }
    }

    ~Logger() {
        if (logStream.is_open()) {
            logStream.close();
        }
    }

    void log(const std::string& message) {
        std::lock_guard<std::mutex> guard(logMutex);
        std::string timestamp = getCurrentTime();
        logStream << "[" << timestamp << "] " << message << std::endl;
        std::cout << "[" << timestamp << "] " << message << std::endl; // Optional console output
    }

private:
    std::string logFileName;
    std::ofstream logStream;
    std::mutex logMutex;

    std::string getCurrentTime() {
        std::time_t now = std::time(nullptr);
        char buf[100];
        std::strftime(buf, sizeof(buf), "%Y-%m-%d %H:%M:%S", std::localtime(&now));
        return buf;
    }
};

// Example usage
extern "C" {
    void log_example() {
        Logger logger("autopilot.log"); // Log file name
        logger.log("Autopilot system initialized.");
        logger.log("GPS sensor activated.");
        logger.log("LiDAR sensor activated.");
    }
}
