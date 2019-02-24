#ifndef OSAUDIENCE_H
#define OSAUDIENCE_H

#include <vector>
#include <stdlib.h>
#include "OSJSONBuilder.h"

class OSAudience 
{
    public:
        OSAudience(char *playerId);
        OSAudience(std::vector<char *> playerIds);
        OSAudience(std::vector<char *> includedSegments, std::vector<char *> excludedSegments);

        bool requiresApiKey();

        void validAudience(char **error);
        
        void buildAudienceJson(OSJSONBuilder &builder);

    private:
        std::vector<char *> _playerIds;

        std::vector<char *> _includedSegments;

        std::vector<char *> _excludedSegments;
        
        bool _audienceRequiresApiKey;
};

#endif