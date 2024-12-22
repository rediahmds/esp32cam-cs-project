#ifndef IOT_H
#define IOT_H

#include "credentials.h"

void initWiFi(const char *apName = "K3-Miawww", const char *apPassword = "miaw123");
void initWiFiManually(char *ssid = MANUAL_SSID, char *password = MANUAL_PASSWORD);
void initBlynk();
void runBlynk();

#endif