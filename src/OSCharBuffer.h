#ifndef OSCHARBUFFER_H
#define OSCHARBUFFER_H

#include <stdlib.h>

// To prevent heap fragmentation, the SDK uses this char buffer
// to build up the JSON payload rather than generating large
// numbers of temporary strings

// NOTE: The OSCharBuffer's stringBuffer is manually allocated memory 
//and must be free'd by the owner of the char buffer

class OSCharBuffer 
{
    public:
        OSCharBuffer();

        // Concatenates the string buffer with the passed in text
        // Returns a boolean indicating if the operation was successful
        // If out-of-memory this function returns false
        bool addText(char *text);
        
        char *stringBuffer;
    
    private:
        bool growBuffer(char *text, size_t addSize);

        // Represents the number of characters the char buffer can contain
        size_t size;

        // Represents the current number of chars added to the buffer
        size_t index;
};

#endif