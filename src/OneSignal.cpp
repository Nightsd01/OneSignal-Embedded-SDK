#include "OneSignal.h"
#include "OSJSONBuilder.h"
#include <stdio.h>

#define ONESIGNAL_POST_NOTIFICATION_URL "https://onesignal.com/api/v1/notifications"

OneSignal::OneSignal(char *appId, char *apiKey)
{
    _appId = appId;
    _apiKey = apiKey;
}

OneSignal::OneSignal(char *appId)
{
    _appId = appId;
}

void printError(char *error)
{
    printf("OneSignal Error: ");
    printf(error);
    printf("\n");
}

const char* OneSignal::sendNotificationToAudience(OSNotification &notification, OSAudience &audience) 
{
    char *error = NULL;

    audience.validAudience(&error);

    if (error != NULL) {
        printError(error);
        return "";
    }
    
    notification.validNotification(&error);

    if (error != NULL) {
        printError(error);
        return "";
    }

    if (audience.requiresApiKey() && _apiKey == NULL) {
        printError("To send a notification to a segment, you must initialize the SDK with your private API key");
        return "";
    }

    OSJSONBuilder builder;

    notification.buildNotificationJson(_appId, audience, builder);
    
    const char *result = syncMakePOSTRequest(ONESIGNAL_POST_NOTIFICATION_URL, builder.stringValue(), _apiKey);

    return result;
}

const char* OneSignal::sendNotificationToPlayerId(char *playerId, OSNotification &notification)
{
    OSAudience audience(playerId);

    sendNotificationToAudience(notification, audience);
}
