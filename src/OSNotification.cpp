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

// Due to the severe memory constraints of embedded platforms like ESP8266,
// we build a JSON string directly instead of using a JSON library

// TODO: addJsonValue() returns a boolean indicating if the 
// operation was successful. This builder should start checking
// this return value and failing if it is false
char* OSNotification::buildNotificationJson(char *appId, OSAudience audience) 
{
    buf.addText("{");
    
    if (language == NULL) 
        language = "en";
    
    addJsonValue(StringType, "app_id", appId, &buf, true);

    buf.addText(",");

    audience.buildAudienceJson(&buf);

    if (contents != NULL) {
        char *contentsJson = singleValueJsonObject(language, contents, StringType);
        addJsonValue(ObjectType, "contents", contentsJson, &buf);
        free(contentsJson);
    }

    if (headings != NULL) {
        char *headingsJson = singleValueJsonObject(language, headings, StringType);
        addJsonValue(ObjectType, "headings", headingsJson, &buf);
        free(headingsJson);
    }

    if (subtitle != NULL) {
        char *subtitleJson = singleValueJsonObject(language, subtitle, StringType);
        addJsonValue(ObjectType, "subtitle", subtitleJson, &buf);
        free(subtitleJson);
    }

    if (mutableContent)
        addJsonValue(ScalarType, "mutable_content", "1", &buf);

    if (contentAvailable)
        addJsonValue(ScalarType, "content_available", "1", &buf);
    
    if (url != NULL)
        addJsonValue(StringType, "url", url, &buf);

    if (androidBigPicture != NULL)
        addJsonValue(StringType, "big_picture", androidBigPicture, &buf);

    if (iosCategory != NULL)
        addJsonValue(StringType, "ios_category", iosCategory, &buf);
    
    if (sendAfter != NULL)
        addJsonValue(StringType, "send_after", sendAfter, &buf);
    
    if (data != NULL)
        addJsonValue(ObjectType, "data", data, &buf);
    
    if (iosAttachments != NULL)
        addJsonValue(ObjectType, "ios_attachments", iosAttachments, &buf);
    
    if (buttons != NULL) 
        addJsonValue(ObjectType, "buttons", buttons, &buf);

    if (androidSmallIcon != NULL)
        addJsonValue(ObjectType, "small_icon", androidSmallIcon, &buf);
    
    if (androidLargeIcon != NULL)
        addJsonValue(ObjectType, "large_icon", androidLargeIcon, &buf);

    buf.addText("}");

    return buf.stringBuffer;
}