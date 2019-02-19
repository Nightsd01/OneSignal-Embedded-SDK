#include "OneSignal.h"

#define ONESIGNAL_POST_NOTIFICATION_URL "https://onesignal.com/api/v1/notifications"

OneSignal::OneSignal(char *appId, char *apiKey)
{
    _appId = appId;
    _apiKey = apiKey;
}

String OneSignal::sendNotificationToAudience(OSNotification notification, OSAudience audience) 
{
    char *body = notification.buildNotificationJson(_appId, audience);

    String bodyString = String(body);

    free(body);
    
    String result = syncMakePOSTRequest(ONESIGNAL_POST_NOTIFICATION_URL, bodyString, String(_apiKey));

    return result;
}

String OneSignal::sendNotificationToPlayerId(char *playerId, OSNotification notification)
{
    OSAudience audience(playerId);

    sendNotificationToAudience(notification, audience);
}
