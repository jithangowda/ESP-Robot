#ifndef MOTORCONTROL_H
#define MOTORCONTROL_H

#include <Arduino.h>

class MotorControl
{
public:
    MotorControl();
    void setupMotors();
    void stopMotors();
    void moveForward(int speed = 200);
    void moveBackward(int speed = 200);
    void turnLeft(int speed = 200);
    void turnRight(int speed = 200);
    void blinkLED();

private:
    // Motor driver pins (Front)
    const int FRONT_ENA_FL = 14; // Blue
    const int FRONT_IN1_FL = 12; // Green
    const int FRONT_IN2_FL = 13; // Yellow
    const int FRONT_IN3_FR = 25; // Orange
    const int FRONT_IN4_FR = 26; // Red
    const int FRONT_ENB_FR = 27; // Brown

    // Motor driver pins (Back)
    const int BACK_ENA_BR = 4;  // Purple
    const int BACK_IN1_BR = 2;  // Gray
    const int BACK_IN2_BR = 15; // White
    const int BACK_IN3_BL = 16; // Black
    const int BACK_IN4_BL = 17; // Brown
    const int BACK_ENB_BL = 5;  // Red
};

#endif