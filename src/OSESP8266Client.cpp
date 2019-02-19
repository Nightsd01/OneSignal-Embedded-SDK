#ifdef OS_ESP8266
#include "OSESP8266Client.h"
#include <ESP8266WiFi.h>
#include <ESP8266HTTPClient.h>

String syncMakePOSTRequest(String address, String body, String apiKey) 
{
    if (WiFi.status() != WL_CONNECTED) {
        return "Not connected to the internet";
    }

    HTTPClient client;
    client.begin(address);
    client.addHeader("Authorization", "Basic " + apiKey);
    client.addHeader("Content-Type", "application/json");
    
    client.POST(body);

    String response = client.getString();

    client.end();

    return response;
}

#endif