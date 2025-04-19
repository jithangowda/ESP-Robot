#include <Arduino.h>
#include <ESPConnection.h>
#include <WiFiUdp.h>

ESPConnection connection("ESP32_Robot", "robot123");
WiFiUDP commandUdp;
const int COMMAND_PORT = 4212;

// Motor driver pins
#define IN1 27
#define IN2 26
#define IN3 25
#define IN4 33

void setupMotors()
{
  pinMode(IN1, OUTPUT);
  pinMode(IN2, OUTPUT);
  pinMode(IN3, OUTPUT);
  pinMode(IN4, OUTPUT);
  digitalWrite(IN1, LOW);
  digitalWrite(IN2, LOW);
  digitalWrite(IN3, LOW);
  digitalWrite(IN4, LOW);
}

void stopMotors()
{
  digitalWrite(IN1, LOW);
  digitalWrite(IN2, LOW);
  digitalWrite(IN3, LOW);
  digitalWrite(IN4, LOW);
}

void moveForward()
{
  digitalWrite(IN1, HIGH);
  digitalWrite(IN2, LOW);
  digitalWrite(IN3, HIGH);
  digitalWrite(IN4, LOW);
}

void moveBackward()
{
  digitalWrite(IN1, LOW);
  digitalWrite(IN2, HIGH);
  digitalWrite(IN3, LOW);
  digitalWrite(IN4, HIGH);
}

void turnLeft()
{
  digitalWrite(IN1, LOW);
  digitalWrite(IN2, HIGH);
  digitalWrite(IN3, HIGH);
  digitalWrite(IN4, LOW);
}

void turnRight()
{
  digitalWrite(IN1, HIGH);
  digitalWrite(IN2, LOW);
  digitalWrite(IN3, LOW);
  digitalWrite(IN4, HIGH);
}

void handleCommand(const String &cmd)
{
  Serial.print("Command: ");
  Serial.println(cmd);

  if (cmd == "forward")
    moveForward();
  else if (cmd == "backward")
    moveBackward();
  else if (cmd == "left")
    turnLeft();
  else if (cmd == "right")
    turnRight();
  else if (cmd == "stop")
    stopMotors();
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
  setupMotors();

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
