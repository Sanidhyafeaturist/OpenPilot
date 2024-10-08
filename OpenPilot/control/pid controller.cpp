#include "pidcontroller.h"

PIDController::PIDController(float p, float i, float d) 
    : Kp(p), Ki(i), Kd(d), prevError(0), integral(0) {}

float PIDController::compute(float setpoint, float measured_value, float dt) {
    float error = setpoint - measured_value;
    integral += error * dt;
    float derivative = (error - prevError) / dt;

    float output = Kp * error + Ki * integral + Kd * derivative;

    prevError = error;
    return output;
}
