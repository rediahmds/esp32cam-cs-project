#include "ota.h"
#include "ota/credentials.h"

void beginOTA(AsyncWebServer *server)
{
		ElegantOTA.setAuth((char*)OTA_USERNAME, (char*)OTA_PASSWORD);
		ElegantOTA.setAutoReboot(true);
		ElegantOTA.begin(server);
}

void loopOTA()
{
		ElegantOTA.loop();
}