#include "OSNotification.h"
#include "OSJSONHelper.h"
#include <stdlib.h>

OSNotification::OSNotification()
{
    language = NULL;
    contents = NULL;
    headings = NULL;
    subtitle = NULL;
    url = NULL;
    androidBigPicture = NULL;
    iosCategory = NULL;
    sendAfter = NULL;
    data = NULL;
    iosAttachments = NULL;
    buttons = NULL;
    androidSmallIcon = NULL;
    androidLargeIcon = NULL;
}

void OSNotification::validNotification(char **error)
{
    if (contents == NULL && !contentAvailable)
        *error = "Notification must include contents, or if you are sending a silent notification, contentAvailable must be set to TRUE";
}

// Due to the severe memory constraints of embedded platforms like ESP8266,
// we build a JSON string directly instead of using a JSON library

// TODO: addJsonValue() returns a boolean indicating if the 
// operation was successful. This builder should start checking
// this return value and failing if it is false
void OSNotification::buildNotificationJson(char *appId, OSAudience &audience, OSJSONBuilder &builder)
{
    if (language == NULL) 
        language = "en";
    
    builder.addJSONValue(StringType, "app_id", appId);

    audience.buildAudienceJson(builder);

    if (contents != NULL)
        builder.addSinglePropertyJSONObject("contents", language, contents, StringType);

    if (headings != NULL)
        builder.addSinglePropertyJSONObject("headings", language, headings, StringType);

    if (subtitle != NULL)
        builder.addSinglePropertyJSONObject("subtitle", language, subtitle, StringType);

    if (mutableContent)
        builder.addJSONValue(ScalarType, "mutable_content", "1");

    if (contentAvailable)
        builder.addJSONValue(ScalarType, "content_available", "1");
    
    if (url != NULL)
        builder.addJSONValue(StringType, "url", url);

    if (androidBigPicture != NULL)
        builder.addJSONValue(StringType, "big_picture", androidBigPicture);

    if (iosCategory != NULL)
        builder.addJSONValue(StringType, "ios_category", iosCategory);
    
    if (sendAfter != NULL)
        builder.addJSONValue(StringType, "send_after", sendAfter);
    
    if (data != NULL)
        builder.addJSONValue(ObjectType, "data", data);
    
    if (iosAttachments != NULL)
        builder.addJSONValue(ObjectType, "ios_attachments", iosAttachments);
    
    if (buttons != NULL) 
        builder.addJSONValue(ObjectType, "buttons", buttons);

    if (androidSmallIcon != NULL)
        builder.addJSONValue(StringType, "small_icon", androidSmallIcon);
    
    if (androidLargeIcon != NULL)
        builder.addJSONValue(StringType, "large_icon", androidLargeIcon);
}