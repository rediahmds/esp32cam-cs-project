#ifndef IOT_H
#define IOT_H

#include "credentials.h"

void initWiFi();
void initWiFiManually(char *ssid = (char *)MANUAL_SSID, char *password = (char *)MANUAL_PASSWORD);
bool checkInternetAvailability();
void watchSignalStrength();

void initBlynk();
void runBlynk();
void testBlynk();
void sendNetworkNameBlynk(const char *name);
void sendStreamURLBlynk(char *url);
void sendSignalStrengthBlynk(char quality[]);

#endif