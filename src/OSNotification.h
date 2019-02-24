#ifndef OSNOTIFICATION_H
#define OSNOTIFICATION_H

#include "OSAudience.h"
#include "OSJSONBuilder.h"

class OSNotification 
{
    public:
        OSNotification();

        // The string returned from this function must be free'd once
        // it has been used
        void buildNotificationJson(char *appId, OSAudience &audience, OSJSONBuilder &builder);

        void validNotification(char **error);

        char *contents;
        char *headings;
        char *subtitle;
        char *language; //defaults to "en" for English

        bool mutableContent;
        bool contentAvailable;

        char *url;
        char *androidBigPicture;
        char *iosCategory;
        char *sendAfter;
        char *androidSmallIcon;
        char *androidLargeIcon;

        /** 
         * The following properties represent JSON fields on
         * the OSNotification. Due to severe memory constraints
         * on embedded devices, we leave it up to you 
         * to build JSON strings for these fields.
        */

        /** Additional data sent to the client */
        char *data;

        /** 
         * Attachments sent to iOS
         * ie. {"id1" : "https://www.mywebsite.com/myimage.jpg"}
        */
        char *iosAttachments;

        /**
         * Array of JSON button objects
         * ie. [{"id" : "button1", "text" : "Test Button"}]
        */
        char *buttons;
};

#endif