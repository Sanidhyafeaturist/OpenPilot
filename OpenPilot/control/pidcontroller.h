#ifndef PID_CONTROLLER_H
#define PID_CONTROLLER_H

class PIDController {
public:
    PIDController(float p, float i, float d);
    float compute(float setpoint, float measured_value, float dt);

private:
    float Kp;
    float Ki;
    float Kd;
    float prevError;
    float integral;
};

#endif // PID_CONTROLLER_H
