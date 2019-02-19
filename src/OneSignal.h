#ifndef ONESIGNAL_H
#define ONESIGNAL_H

// Currently only compiling for ESP32 & ESP8266 is supported

// UNCOMMENT THIS LINE IF YOU ARE COMPILING FOR THE ESP8266
// #include "OSESP8266Client.h"

// UNCOMMENT THIS LINE IF YOU ARE COMPILING FOR THE ESP32
#include "OSESP32Client.h"

#include <Arduino.h>
#include "OSNotification.h"

class OneSignal
{
    private:
        char *_appId;
        char *_apiKey;

    public:
        OneSignal(char *appId, char *apiKey);
        String sendNotificationToAudience(OSNotification notification, OSAudience audience);
        String sendNotificationToPlayerId(char *playerId, OSNotification notification);
};

#endif