#include "OSJSONHelper.h"

namespace JSONHelper 
{
    void addPropertyToBuffer(char *property, OSCharBuffer &buf, bool beginning)
    {
        if (!beginning)
            buf.addText(",");

        buf.addText("\"");
        buf.addText(property);
        buf.addText("\":");
    }

    void addSingleValueJSONObject(char *property, char *value, OSCharBuffer &buf, JSONValueType type)
    {
        buf.addText("{\"");
        buf.addText(property);

        switch (type) {
            case StringType:
                buf.addText("\":\"");
                buf.addText(value);
                buf.addText("\"}");
                break;
            default:
                buf.addText("\":");
                buf.addText(value);
                buf.addText("}");
                break;
        }
    }

    void addSinglePropertyJSONObject(char *property, char *subProperty, char *subValue, OSCharBuffer &buf, JSONValueType type, bool beginning)
    {
        addPropertyToBuffer(property, buf, beginning);

        addSingleValueJSONObject(subProperty, subValue, buf, type);
    }

    void addJSONValue(JSONValueType type, char *property, char *value, OSCharBuffer &buf, bool beginning) 
    {
        addPropertyToBuffer(property, buf, beginning);
        
        switch (type) {
            case StringType:
                buf.addText("\"");
                buf.addText(value);
                buf.addText("\"");
                break;
            default:
                buf.addText(value);
                break;
        }
    }

    void addJSONArray(std::vector<char *> values, OSCharBuffer &buf)
    {
        buf.addText("[");

        for (int i = 0; i < values.size(); i++) {
            buf.addText("\"");
            buf.addText(values.at(i));
            buf.addText("\"");

            if (i + 1 < values.size()) 
                buf.addText(",");
        }

        buf.addText("]");
    }
}