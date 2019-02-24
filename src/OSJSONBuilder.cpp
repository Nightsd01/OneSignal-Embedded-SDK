#include "OSJSONBuilder.h"

OSJSONBuilder::OSJSONBuilder() 
{
    beginning = true;
    addedEnd = false;
    buf.addText("{");
}


// Copying the JSON builder is very expensive
// and should be avoided if possible
OSJSONBuilder::OSJSONBuilder(OSJSONBuilder const &other)
{
    beginning = other.beginning;
    addedEnd = other.addedEnd;
    buf = OSCharBuffer(other.buf);
}

void OSJSONBuilder::addJSONValue(JSONValueType type, char *property, char *value)
{
    JSONHelper::addJSONValue(type, property, value, buf, beginning);
    beginning = false;
}

void OSJSONBuilder::addSinglePropertyJSONObject(char *property, char *subProperty, char *subValue, JSONValueType type)
{
    JSONHelper::addSinglePropertyJSONObject(property, subProperty, subValue, buf, type, beginning);
    beginning = false;
}

void OSJSONBuilder::addJSONArray(char *property, std::vector<char *> values)
{
    JSONHelper::addPropertyToBuffer(property, buf, beginning);
    JSONHelper::addJSONArray(values, buf);
    beginning = false;
}

char* OSJSONBuilder::stringValue()
{
    if (!addedEnd) {
        buf.addText("}");
        addedEnd = true;
    }

    return buf.stringBuffer;
}