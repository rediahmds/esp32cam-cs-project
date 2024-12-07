#include <WiFiManager.h>

WiFiManager wm;

void initWiFi(char *apName = "K3-Miawww 😽", char *apPassword = "miaw123")
{
    Serial.println("[INFO] Connecting to a WiFi network...");
    bool isConnected = wm.autoConnect(apName, apPassword);
    if (isConnected)
    {
        Serial.println("[SUCCESS] Connected to a WiFi network! Yeayy!");
    }
    else
    {
        Serial.println("[**FAILED**] Could not connect to a WiFi network :(");
        Serial.println("[INFO] Starting an access point instead...");
        Serial.print("[INFO] AP Name: ");
        Serial.print(apName);
    }
}