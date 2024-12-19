#include <Arduino.h>
#include "iot/iot.h"
#include "camserver/WifiCam.hpp"

esp32cam::Resolution initialResolution;
WebServer server(80);

void setup()
{
  // put your setup code here, to run once:
  Serial.begin(115200);
  initWiFi();
  initBlynk();
}

void loop()
{
  runBlynk();
}
