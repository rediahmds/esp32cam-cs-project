#include "credentials.h"
#include <WiFiManager.h>
#include <Ethernet.h>
#include <BlynkSimpleEthernet.h>

WiFiManager wm;

void initWiFi(const char *apName = "K3-Miawww 😽", const char *apPassword = "miaw123")
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

void initWiFiManually(char *ssid, char *password)
{
    WiFi.mode(WIFI_STA); // Optional
    WiFi.begin(ssid, password);
    Serial.println("[INFO] Connecting");

    while (WiFi.status() != WL_CONNECTED)
    {
        Serial.print(".");
        delay(100);
    }

    Serial.println("\n[SUCCESS] Connected to the WiFi network");
    Serial.print("IP: ");
    Serial.println(WiFi.localIP());
}

void initBlynk()
{
    char auth[] = BLYNK_AUTH_TOKEN;
    Blynk.config((char *)auth, BLYNK_CUSTOM_HOST_NAME, BLYNK_CUSTOM_PORT);
}

void runBlynk()
{
    Blynk.run();
}