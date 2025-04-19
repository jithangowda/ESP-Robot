#include "ESPConnection.h"

ESPConnection::ESPConnection(const char *apName, const char *apPassword)
    : _apName(apName), _apPassword(apPassword), serverFound(false) {}

void ESPConnection::begin()
{
    Serial.begin(115200);
    pinMode(LED_BUILTIN, OUTPUT);
    Serial.println("Booting...");

    WiFiManager wm;
    if (!wm.autoConnect(_apName, _apPassword))
    {
        Serial.println("WiFi failed.");
        ESP.restart();
        delay(5000);
    }

    Serial.print("Connected to: ");
    Serial.println(WiFi.SSID());
    Serial.print("Local IP: ");
    Serial.println(WiFi.localIP());

    udp.begin(UDP_PORT);
    Serial.println("Listening for UDP broadcasts...");
}

void ESPConnection::blinkLED(int times)
{
    for (int i = 0; i < times; i++)
    {
        digitalWrite(LED_BUILTIN, HIGH);
        delay(300);
        digitalWrite(LED_BUILTIN, LOW);
        delay(300);
    }
}

void ESPConnection::sendESPConnectedMessage()
{
    static bool messageSent = false; // Static flag to send the message only once

    if (serverFound && !serverIP.isEmpty() && !messageSent)
    {
        WiFiUDP udp;
        udp.begin(4211); // Connect to a different port for sending messages to the server
        String message = "ESP Connected";

        // Convert the message to a byte array and send it
        udp.beginPacket(serverIP.c_str(), 4211);                 // Use the server's IP and the server's listening port
        udp.write((uint8_t *)message.c_str(), message.length()); // Write message as byte array
        udp.endPacket();
        messageSent = true; // Mark the message as sent
        Serial.println("[ESP32] Sent ESP Connected message to server.");
    }
}

void ESPConnection::listenForServer()
{
    if (serverFound)
    {
        sendESPConnectedMessage(); // Send confirmation message
        return;                    // Skip listening for further UDP messages
    }

    char incomingPacket[255];
    int packetSize = udp.parsePacket();
    if (packetSize)
    {
        int len = udp.read(incomingPacket, 255);
        if (len > 0)
        {
            incomingPacket[len] = '\0';
        }

        Serial.print("Received UDP: ");
        Serial.println(incomingPacket);

        if (String(incomingPacket).startsWith("SERVER_IP:") && !serverFound)
        {
            serverIP = String(incomingPacket).substring(10);
            Serial.print("✅ Server IP received: ");
            Serial.println(serverIP);
            serverFound = true;

            blinkLED(3);
            digitalWrite(LED_BUILTIN, HIGH); // Keep LED ON after server found
            Serial.println("Connected to server.");
            Serial.print("Server IP: ");
            Serial.println(serverIP);
        }
    }
}

bool ESPConnection::isServerFound()
{
    return serverFound;
}