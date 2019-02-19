#ifdef OS_ESP8266

#ifndef OSESP8266CLIENT_H 
#define OSESP8266CLIENT_H

#include <Arduino.h>

String syncMakePOSTRequest(String address, String body, String apiKey);

#endif
#endif