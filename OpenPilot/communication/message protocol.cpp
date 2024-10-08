#include "messageprotocol.h"
#include <iostream>

std::string encodeMessage(const std::string& message) {
    return "MSG:" + message;
}

std::string decodeMessage(const std::string& message) {
    if (message.rfind("MSG:", 0) == 0) {
        return message.substr(4);
    }
    return "";
}

void sendMessage(const std::string& message) {
    std::string encoded = encodeMessage(message);
    sendData(encoded.c_str());
}

void receiveMessage(const std::string& encodedMessage) {
    std::string decoded = decodeMessage(encodedMessage);
    if (!decoded.empty()) {
        processMessage(decoded);
    }
}

void sendData(const char* data) {
    // This function is intentionally empty as sendData is implemented in telemetry.cpp
}

void processMessage(const std::string& message) {
    std::cout << message << std::endl;
}
