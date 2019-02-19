#include "OSJSONHelper.h"

void addJsonValue(JSONValueType type, char *property, char *value, OSCharBuffer *buf, bool beginning) 
{
    if (!beginning)
        buf->addText(",");

    buf->addText("\"");
    buf->addText(property);
    buf->addText("\":");
    
    switch (type) {
        case StringType:
            buf->addText("\"");
            buf->addText(value);
            buf->addText("\"");
            break;
        default:
            buf->addText(value);
            break;
    }
}

char* singleValueJsonObject(char *property, char *value, JSONValueType type)
{   
    OSCharBuffer temp;
    temp.addText("{\"");
    temp.addText(property);

    switch (type) {
        case StringType:
            temp.addText("\":\"");
            temp.addText(value);
            temp.addText("\"}");
            break;
        default:
            temp.addText("\":");
            temp.addText(value);
            temp.addText("}");
            break;
    }

    return temp.stringBuffer;
}

void buildJsonArray(std::vector<char *> values, OSCharBuffer *buf)
{
    buf->addText("[");

    for (int i = 0; i < values.size(); i++) {
        buf->addText("\"");
        buf->addText(values.at(i));
        buf->addText("\"");

        if (i + 1 < values.size()) 
            buf->addText(",");
    }

    buf->addText("]");
}