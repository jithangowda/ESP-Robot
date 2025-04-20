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
    pinMode(FRONT_IN1_FL, OUTPUT); // Front Left IN1
    pinMode(FRONT_IN2_FL, OUTPUT); // Front Left IN2
    pinMode(FRONT_IN3_FR, OUTPUT); // Front Right IN3
    pinMode(FRONT_IN4_FR, OUTPUT); // Front Right IN4
    pinMode(FRONT_ENA_FL, OUTPUT); // Front Left Enable
    pinMode(FRONT_ENB_FR, OUTPUT); // Front Right Enable

    // Back motor pins
    pinMode(BACK_IN1_BR, OUTPUT); // Back Right IN1
    pinMode(BACK_IN2_BR, OUTPUT); // Back Right IN2
    pinMode(BACK_IN3_BL, OUTPUT); // Back Left IN3
    pinMode(BACK_IN4_BL, OUTPUT); // Back Left IN4
    pinMode(BACK_ENA_BR, OUTPUT); // Back Right Enable
    pinMode(BACK_ENB_BL, OUTPUT); // Back Left Enable

    // Initialize all motor pins to LOW
    digitalWrite(FRONT_IN1_FL, LOW);
    digitalWrite(FRONT_IN2_FL, LOW);
    digitalWrite(FRONT_IN3_FR, LOW);
    digitalWrite(FRONT_IN4_FR, LOW);

    digitalWrite(BACK_IN1_BR, LOW);
    digitalWrite(BACK_IN2_BR, LOW);
    digitalWrite(BACK_IN3_BL, LOW);
    digitalWrite(BACK_IN4_BL, LOW);

    // Disable motors initially
    analogWrite(FRONT_ENA_FL, 0); // PWM: Speed = 0
    analogWrite(FRONT_ENB_FR, 0);
    analogWrite(BACK_ENA_BR, 0);
    analogWrite(BACK_ENB_BL, 0);
}

void MotorControl::stopMotors()
{
    // Stop all motors by disabling them
    analogWrite(FRONT_ENA_FL, 0); // PWM: Speed = 0
    analogWrite(FRONT_ENB_FR, 0);
    analogWrite(BACK_ENA_BR, 0);
    analogWrite(BACK_ENB_BL, 0);
}

void MotorControl::moveForward(int speed)
{
    // Enable all motors with the given speed
    analogWrite(FRONT_ENA_FL, speed);
    analogWrite(FRONT_ENB_FR, speed);
    analogWrite(BACK_ENA_BR, speed);
    analogWrite(BACK_ENB_BL, speed);

    // Front Left Motor Forward
    digitalWrite(FRONT_IN1_FL, HIGH);
    digitalWrite(FRONT_IN2_FL, LOW);

    // Front Right Motor Forward
    digitalWrite(FRONT_IN3_FR, HIGH);
    digitalWrite(FRONT_IN4_FR, LOW);

    // Back Left Motor Forward
    digitalWrite(BACK_IN3_BL, HIGH);
    digitalWrite(BACK_IN4_BL, LOW);

    // Back Right Motor Forward
    digitalWrite(BACK_IN1_BR, HIGH);
    digitalWrite(BACK_IN2_BR, LOW);
}

void MotorControl::moveBackward(int speed)
{
    // Enable all motors with the given speed
    analogWrite(FRONT_ENA_FL, speed);
    analogWrite(FRONT_ENB_FR, speed);
    analogWrite(BACK_ENA_BR, speed);
    analogWrite(BACK_ENB_BL, speed);

    // Front Left Motor Backward
    digitalWrite(FRONT_IN1_FL, LOW);
    digitalWrite(FRONT_IN2_FL, HIGH);

    // Front Right Motor Backward
    digitalWrite(FRONT_IN3_FR, LOW);
    digitalWrite(FRONT_IN4_FR, HIGH);

    // Back Left Motor Backward
    digitalWrite(BACK_IN3_BL, LOW);
    digitalWrite(BACK_IN4_BL, HIGH);

    // Back Right Motor Backward
    digitalWrite(BACK_IN1_BR, LOW);
    digitalWrite(BACK_IN2_BR, HIGH);
}

void MotorControl::turnLeft(int speed)
{
    // Enable all motors with the given speed
    analogWrite(FRONT_ENA_FL, speed);
    analogWrite(FRONT_ENB_FR, speed);
    analogWrite(BACK_ENA_BR, speed);
    analogWrite(BACK_ENB_BL, speed);

    // Front Left Motor Backward
    digitalWrite(FRONT_IN1_FL, LOW);
    digitalWrite(FRONT_IN2_FL, HIGH);

    // Front Right Motor Forward
    digitalWrite(FRONT_IN3_FR, HIGH);
    digitalWrite(FRONT_IN4_FR, LOW);

    // Back Left Motor Backward
    digitalWrite(BACK_IN3_BL, LOW);
    digitalWrite(BACK_IN4_BL, HIGH);

    // Back Right Motor Forward
    digitalWrite(BACK_IN1_BR, HIGH);
    digitalWrite(BACK_IN2_BR, LOW);
}

void MotorControl::turnRight(int speed)
{
    // Enable all motors with the given speed
    analogWrite(FRONT_ENA_FL, speed);
    analogWrite(FRONT_ENB_FR, speed);
    analogWrite(BACK_ENA_BR, speed);
    analogWrite(BACK_ENB_BL, speed);

    // Front Left Motor Forward
    digitalWrite(FRONT_IN1_FL, HIGH);
    digitalWrite(FRONT_IN2_FL, LOW);

    // Front Right Motor Backward
    digitalWrite(FRONT_IN3_FR, LOW);
    digitalWrite(FRONT_IN4_FR, HIGH);

    // Back Left Motor Forward
    digitalWrite(BACK_IN3_BL, HIGH);
    digitalWrite(BACK_IN4_BL, LOW);

    // Back Right Motor Backward
    digitalWrite(BACK_IN1_BR, LOW);
    digitalWrite(BACK_IN2_BR, HIGH);
}