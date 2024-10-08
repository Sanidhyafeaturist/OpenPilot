#include "telemetry.h"
#include <cstring>
#include <iostream>
#include <sys/socket.h>
#include <arpa/inet.h>
#include <unistd.h>

const char* SERVER_IP = "192.168.1.100"; // Replace with your server's IP address
const int SERVER_PORT = 8080; // Replace with your server's port

int socket_fd;

void initializeSocket() {
    socket_fd = socket(AF_INET, SOCK_STREAM, 0);
    struct sockaddr_in server_addr;
    server_addr.sin_family = AF_INET;
    server_addr.sin_port = htons(SERVER_PORT);
    inet_pton(AF_INET, SERVER_IP, &server_addr.sin_addr);
    
    connect(socket_fd, (struct sockaddr*)&server_addr, sizeof(server_addr));
}

void sendTelemetry(float latitude, float longitude, float altitude, float speed) {
    char message[100];
    snprintf(message, sizeof(message), "LAT:%.6f LON:%.6f ALT:%.2f SPD:%.2f", latitude, longitude, altitude, speed);
    sendData(message);
}

void sendData(const char* data) {
    send(socket_fd, data, strlen(data), 0);
}

void closeSocket() {
    close(socket_fd);
}
