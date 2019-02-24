#ifdef OS_ESP8266
#include "OSESP8266Client.h"
#include <ESP8266WiFi.h>
#include <ESP8266HTTPClient.h>

const char* syncMakePOSTRequest(char *address, char *body, char *apiKey) 
{
    if (WiFi.status() != WL_CONNECTED) {
        return "Not connected to the internet";
    }

    HTTPClient client;
    client.begin(String(address));
    client.addHeader("Authorization", "Basic " + String(apiKey));
    client.addHeader("Content-Type", "application/json");
    
    client.POST(String(body));

    char *response = client.getString().c_str();

    client.end();

    return response;
}

#endif