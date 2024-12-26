#include "AsyncCam.hpp"
#include <WiFi.h>
#include "iot/iot.h"
#include "ota/ota.h"

using namespace esp32cam;

Resolution initialResolution = esp32cam::Resolution::find(800, 600);
Resolution currentResolution = initialResolution;

AsyncWebServer server(80);

void initCam(int minWidth, int minHeight, int quality)
{
	Resolution initialResolution = Resolution::find(minWidth, minHeight);

	Config config;
	config.setPins(pins::AiThinker);
	config.setResolution(initialResolution);
	config.setJpeg(quality);

	bool isCamBegin = Camera.begin(config);
	if (!isCamBegin)
	{
		Serial.println("[FAILED] Camera cannot be started :(");
		Serial.println("[INFO] Restarting board in 3s...");
		delay(3000);
		ESP.restart();
	}
	Serial.println("[SUCCESS] Camera initialized. Hurrayy :)");
}

void beginServer()
{
	beginOTA(&server);
	server.begin();
}

void handleClient()
{
	loopOTA();
	// esp32cam-asyncweb.h depends on FreeRTOS task API including vTaskDelete, so you must have a
	// non-zero delay in the loop() function; otherwise, FreeRTOS kernel memory cannot be freed
	// properly and the system would run out of memory.
	delay(1);
}

void showStreamURL()
{
	IPAddress ipv4 = WiFi.localIP();
	char url[64];
	snprintf(url, sizeof(url), "http://%d.%d.%d.%d/cam.mjpeg", ipv4[0], ipv4[1], ipv4[2], ipv4[3]);
	sendStreamURLBlynk(url);
}