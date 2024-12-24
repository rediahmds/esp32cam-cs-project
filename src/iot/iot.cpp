#include "credentials.h"
#include <WiFiManager.h>
#include <Ethernet.h>
#include "BlynkSimpleEsp32.h"
#include <ESP32Ping.h>

WiFiManager wm;

bool checkInternetAvailability()
{
    Serial.println("[INFO] Checking internet availability...");
    bool internetAvailable = Ping.ping((char*)BLYNK_CUSTOM_HOST_NAME, 5);
    return internetAvailable;
}

void initWiFi()
{
    WiFi.mode(WIFI_STA);
    Serial.println("[INFO] Using WiFi Manager (Automatic mode)...");
    Serial.println("[INFO] Connecting to a WiFi network...");
    char *apName = (char *)ACCESS_POINT_NAME;
    bool isConnected = wm.autoConnect(apName, (char *)ACCESS_POINT_PASSWORD);
    if (isConnected)
    {
        Serial.println("[SUCCESS] Connected to a WiFi network! Yeayy!");
        bool internetAvailable = checkInternetAvailability();
        if (internetAvailable)
        {
            Serial.println("[SUCCESS] Internet is available! Yeayy!");
            IPAddress ipv4 = WiFi.localIP();
            Serial.printf("[INFO] IP address: %d.%d.%d.%d", ipv4[0], ipv4[1], ipv4[2], ipv4[3]);
        }
        else
        {
            Serial.println("[**FAILED**] Internet is not available :(");
            Serial.println("[INFO] Resetting WiFi settings...");
            wm.resetSettings();
            wm.reboot();
        }
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
    Serial.println("[INFO] Using Manual mode");
    WiFi.mode(WIFI_STA);
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
    Blynk.config((char *)BLYNK_AUTH_TOKEN, (char *)BLYNK_CUSTOM_HOST_NAME, BLYNK_CUSTOM_PORT);
    Blynk.connect();
}

void runBlynk()
{
    Blynk.run();
}

void testBlynk()
{
    Blynk.virtualWrite(V0, "K3-Miaww v2.1");
    delay(1000);
}
