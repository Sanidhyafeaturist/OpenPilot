#ifndef MESSAGE_PROTOCOL_H
#define MESSAGE_PROTOCOL_H

#include <string>

std::string encodeMessage(const std::string& message);
std::string decodeMessage(const std::string& message);
void sendMessage(const std::string& message);
void receiveMessage(const std::string& encodedMessage);
void sendData(const char* data);
void processMessage(const std::string& message);

#endif // MESSAGE_PROTOCOL_H
