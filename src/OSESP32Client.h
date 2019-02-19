#ifndef OSESP32CLIENT_H
#define OSESP32CLIENT_H

#include <Arduino.h>

String syncMakePOSTRequest(String address, String body, String apiKey);

#endif