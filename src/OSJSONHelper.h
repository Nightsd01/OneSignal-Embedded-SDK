#ifndef OSJSONHELPER_H
#define OSJSONHELPER_H

#include <stdlib.h>
#include <vector>
#include "OSCharBuffer.h"

enum JSONValueType 
{
    StringType = 0,
    ObjectType,
    ScalarType
};

// Adds a single key/value JSON property to the OSCharBuffer
void addJsonValue(JSONValueType type, char *property, char *value, OSCharBuffer *buf, bool beginning = false);

// The string returned by this function must be free'd after use
char* singleValueJsonObject(char *property, char *value, JSONValueType type);

// Adds a JSON array of strings to the OSCharBuffer
void buildJsonArray(std::vector<char *> values, OSCharBuffer *buf);

#endif