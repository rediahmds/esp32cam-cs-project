#include "WifiCam.hpp"
#include <WiFi.h>
#include "iot/iot.h"

using namespace esp32cam;

WebServer server(80);

void initCam(int minWidth, int minHeight, int quality)
{
	sendCamStatusMessage("Initializing...");
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
		sendCamStatusMessage("Cannot be started :(");
		delay(3000);
		ESP.restart();
	}
	Serial.println("[SUCCESS] Camera initialized. Hurrayy :)");
	sendCamStatusMessage("Initialized");
}

void beginServer()
{
	server.begin();
}

void handleClient()
{
	server.handleClient();
}

void showStreamURL()
{
	IPAddress ipv4 = WiFi.localIP();
	char url[64];
	snprintf(url, sizeof(url), "http://%d.%d.%d.%d/640x480.mjpeg", ipv4[0], ipv4[1], ipv4[2], ipv4[3]);
	sendStreamURL(url);
}