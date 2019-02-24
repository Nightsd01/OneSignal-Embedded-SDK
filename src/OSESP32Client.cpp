#include "OSESP32Client.h"
#include <WiFi.h>
#include <HTTPClient.h>

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

    const char *response = client.getString().c_str();

    client.end();

    return response;
}