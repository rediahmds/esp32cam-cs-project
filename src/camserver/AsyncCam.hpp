#ifndef ASYNCCAM_HPP
#define ASYNCCAM_HPP

// This macro indicates where to send debug logs.
// Delete this macro to disable debug logging.
#define ESP32CAM_ASYNCWEB_LOGGER Serial

#include <ESPAsyncWebServer.h>
#include "esp32cam-asyncweb.h"

extern esp32cam::Resolution initialResolution;
extern esp32cam::Resolution currentResolution;

extern AsyncWebServer server;

void addRequestHandlers();

void initCam(int minWidth = 1280, int minHeight = 720, int quality = 70);
void beginServer();
void handleClient();
void showStreamURL();

#endif // WIFICAM_HPP