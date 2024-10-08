#ifndef TELEMETRY_H
#define TELEMETRY_H

void initializeSocket();
void sendTelemetry(float latitude, float longitude, float altitude, float speed);
void sendData(const char* data);
void closeSocket();

#endif // TELEMETRY_H
