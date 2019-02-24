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

namespace JSONHelper 
{
    // Adds a single key/value JSON property to the OSCharBuffer
    void addJSONValue(JSONValueType type, char *property, char *value, OSCharBuffer &buf, bool beginning = false);

    // Adds a single-key JSON object to the buffer
    void addSinglePropertyJSONObject(char *property, char *subProperty, char *subValue, OSCharBuffer &buf, JSONValueType type, bool beginning = false);

    // Adds a JSON array of strings to the OSCharBuffer
    void addJSONArray(std::vector<char *> values, OSCharBuffer &buf);

    // Adds a property before a value, ie: "json_property" : 
    void addPropertyToBuffer(char *property, OSCharBuffer &buf, bool beginning);
}

#endif