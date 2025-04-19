#include "MotorControl.h"

MotorControl::MotorControl()
{
    // Constructor: No initialization needed here
}

void MotorControl::blinkLED()
{
    digitalWrite(LED_BUILTIN, HIGH);
    delay(100);
    digitalWrite(LED_BUILTIN, LOW);
}

void MotorControl::setupMotors()
{
    // Front motor pins
    pinMode(FRONT_IN1, OUTPUT);
    pinMode(FRONT_IN2, OUTPUT);
    pinMode(FRONT_IN3, OUTPUT);
    pinMode(FRONT_IN4, OUTPUT);

    // Back motor pins
    pinMode(BACK_IN1, OUTPUT);
    pinMode(BACK_IN2, OUTPUT);
    pinMode(BACK_IN3, OUTPUT);
    pinMode(BACK_IN4, OUTPUT);

    // Initialize all motor pins to LOW
    digitalWrite(FRONT_IN1, LOW);
    digitalWrite(FRONT_IN2, LOW);
    digitalWrite(FRONT_IN3, LOW);
    digitalWrite(FRONT_IN4, LOW);
    digitalWrite(BACK_IN1, LOW);
    digitalWrite(BACK_IN2, LOW);
    digitalWrite(BACK_IN3, LOW);
    digitalWrite(BACK_IN4, LOW);
}

void MotorControl::stopMotors()
{
    // Stop all motors by setting all pins to LOW
    digitalWrite(FRONT_IN1, LOW);
    digitalWrite(FRONT_IN2, LOW);
    digitalWrite(FRONT_IN3, LOW);
    digitalWrite(FRONT_IN4, LOW);
    digitalWrite(BACK_IN1, LOW);
    digitalWrite(BACK_IN2, LOW);
    digitalWrite(BACK_IN3, LOW);
    digitalWrite(BACK_IN4, LOW);
}

void MotorControl::moveForward()
{
    // Front motors forward
    digitalWrite(FRONT_IN1, HIGH);
    digitalWrite(FRONT_IN2, LOW);
    digitalWrite(FRONT_IN3, HIGH);
    digitalWrite(FRONT_IN4, LOW);

    // Back motors forward
    digitalWrite(BACK_IN1, HIGH);
    digitalWrite(BACK_IN2, LOW);
    digitalWrite(BACK_IN3, HIGH);
    digitalWrite(BACK_IN4, LOW);
}

void MotorControl::moveBackward()
{
    // Front motors backward
    digitalWrite(FRONT_IN1, LOW);
    digitalWrite(FRONT_IN2, HIGH);
    digitalWrite(FRONT_IN3, LOW);
    digitalWrite(FRONT_IN4, HIGH);

    // Back motors backward
    digitalWrite(BACK_IN1, LOW);
    digitalWrite(BACK_IN2, HIGH);
    digitalWrite(BACK_IN3, LOW);
    digitalWrite(BACK_IN4, HIGH);
}

void MotorControl::turnLeft()
{
    // Front motors: left wheels backward, right wheels forward
    digitalWrite(FRONT_IN1, LOW);
    digitalWrite(FRONT_IN2, HIGH);
    digitalWrite(FRONT_IN3, HIGH);
    digitalWrite(FRONT_IN4, LOW);

    // Back motors: left wheels backward, right wheels forward
    digitalWrite(BACK_IN1, LOW);
    digitalWrite(BACK_IN2, HIGH);
    digitalWrite(BACK_IN3, HIGH);
    digitalWrite(BACK_IN4, LOW);
}

void MotorControl::turnRight()
{
    // Front motors: left wheels forward, right wheels backward
    digitalWrite(FRONT_IN1, HIGH);
    digitalWrite(FRONT_IN2, LOW);
    digitalWrite(FRONT_IN3, LOW);
    digitalWrite(FRONT_IN4, HIGH);

    // Back motors: left wheels forward, right wheels backward
    digitalWrite(BACK_IN1, HIGH);
    digitalWrite(BACK_IN2, LOW);
    digitalWrite(BACK_IN3, LOW);
    digitalWrite(BACK_IN4, HIGH);
}