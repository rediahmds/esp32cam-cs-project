#ifndef IOT_H
#define IOT_H

#include "credentials.h"

void initWiFi();
void initWiFiManually(char *ssid = (char *)MANUAL_SSID, char *password = (char *)MANUAL_PASSWORD);
void initBlynk();
void runBlynk();
bool checkInternetAvailability();
void testBlynk();
void sendCamStatusMessage(const char *message);

#endif