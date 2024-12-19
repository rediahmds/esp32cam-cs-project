#ifndef WIFICAM_HPP
#define WIFICAM_HPP

#include <esp32cam.h>

#include <WebServer.h>

extern esp32cam::Resolution initialResolution;

extern WebServer server;

void addRequestHandlers();

void initCam(int minWidth = 1024, int minHeight = 768, int quality = 90);
void beginServer();
void handleClient();
void showStreamURL();



#endif  // WIFICAM_HPP