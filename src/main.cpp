#include <Arduino.h>
#include <ESPConnection.h>

ESPConnection connection("ESP32_Robot", "robot123");

void setup()
{
  connection.begin();
}

void loop()
{
  connection.listenForServer();
  if (connection.isServerFound())
  {
    // Server found, do something
  }
}
