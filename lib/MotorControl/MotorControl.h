#ifndef MOTORCONTROL_H
#define MOTORCONTROL_H

#include <Arduino.h>

class MotorControl
{
public:
    MotorControl();
    void setupMotors();
    void stopMotors();
    void moveForward();
    void moveBackward();
    void turnLeft();
    void turnRight();
    void blinkLED();

private:
    // Motor driver pins (Front)
    const int FRONT_ENA = 14; // Blue
    const int FRONT_IN1 = 12; // Green
    const int FRONT_IN2 = 13; // Yellow
    const int FRONT_IN3 = 25; // Orange
    const int FRONT_IN4 = 26; // Red
    const int FRONT_ENB = 27; // Brown

    // Motor driver pins (Back)
    const int BACK_ENA = 4;  // Purple
    const int BACK_IN1 = 2;  // Gray
    const int BACK_IN2 = 15; // White
    const int BACK_IN3 = 16; // Black
    const int BACK_IN4 = 17; // Brown
    const int BACK_ENB = 5;  // Red
};

#endif