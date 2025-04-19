#include <Arduino.h>
#include <WiFiUdp.h>
#include <ESPConnection.h>
#include <MotorControl.h>

ESPConnection connection("ESP32_Robot", "robot123");
WiFiUDP commandUdp;
const int COMMAND_PORT = 4212;

MotorControl motorControl; // Create an instance of the MotorControl class

void handleCommand(const String &cmd)
{
  Serial.print("Command: ");
  Serial.println(cmd);

  motorControl.blinkLED();

  if (cmd == "forward")
    motorControl.moveForward();
  else if (cmd == "backward")
    motorControl.moveBackward();
  else if (cmd == "left")
    motorControl.turnLeft();
  else if (cmd == "right")
    motorControl.turnRight();
  else if (cmd == "stop")
    motorControl.stopMotors();
}

void listenForCommands()
{
  int packetSize = commandUdp.parsePacket();
  if (packetSize)
  {
    char packet[50];
    int len = commandUdp.read(packet, 50);
    if (len > 0)
      packet[len] = '\0';

    handleCommand(String(packet));
  }
}

void setup()
{
  connection.begin();
  motorControl.setupMotors(); // Initialize motors using the MotorControl instance

  // Start listening for commands
  commandUdp.begin(COMMAND_PORT);
  Serial.println("Ready to receive movement commands.");
}

void loop()
{
  connection.listenForServer();

  if (connection.isServerFound())
  {
    listenForCommands();
  }
}