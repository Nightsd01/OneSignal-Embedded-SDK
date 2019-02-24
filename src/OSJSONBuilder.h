#ifndef OSJSONBUILDER_H
#define OSJSONBUILDER_H

#include "OSJSONHelper.h"
#include "OSCharBuffer.h"

class OSJSONBuilder
{
    public:
        OSJSONBuilder();

        // Copying the JSON builder is very expensive
        // and should be avoided if possible
        OSJSONBuilder(OSJSONBuilder const &other);

        // Adds a single key/value pair
        void addJSONValue(JSONValueType type, char *property, char *value);

        // Adds a one-value JSON object to JSON
        // ie. {"property" : {"subProperty" : subValue}}
        void addSinglePropertyJSONObject(char *property, char *subProperty, char *subValue, JSONValueType type);

        // Adds an array property 
        // ie. {"property" : [values...]}
        void addJSONArray(char *property, std::vector<char *> values);

        char* stringValue();

    private:
        OSCharBuffer buf;
        bool beginning;
        bool addedEnd;
};

#endif