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
        char *_appId = NULL;
        char *_apiKey = NULL;

    public:
        // NOTE: The API key is like a password and should never be publicly disclosed
        OneSignal(char *appId, char *apiKey);

        // If you know exactly what player ID's you will use to push to, you do not need the API key
        OneSignal(char *appId);

        // Sends the notification to a given audience 
        const char* sendNotificationToAudience(OSNotification &notification, OSAudience &audience);

        // Convenience function to send the notification to a specific device
        const char* sendNotificationToPlayerId(char *playerId, OSNotification &notification);
};

#endif