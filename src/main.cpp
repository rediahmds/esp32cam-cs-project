#include <Arduino.h>
#include "iot/iot.h"
#include "camserver/AsyncCam.hpp"

void setup()
{
  // put your setup code here, to run once:
  Serial.begin(115200);

  initWiFi();
  // initWiFiManually();
  initBlynk();
  initCam();

  addRequestHandlers();
  beginServer();
  showStreamURL();
}

void loop()
{
  runBlynk();
  handleClient();
  watchSignalStrength();
  testBlynk();
}
