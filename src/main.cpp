#include <Arduino.h>
#include "utils/iot.h"

int counter = 0;

void setup()
{
  // put your setup code here, to run once:
  Serial.begin(115200);
  initWiFi();
}

void loop()
{
  // put your main code here, to run repeatedly:
  Serial.print(counter);
  Serial.println("Hello world");
  delay(2000);
  counter++;
}
