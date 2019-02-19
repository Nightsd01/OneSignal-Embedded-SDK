#include "OSAudience.h"
#include "OSJSONHelper.h"

// Constructor functions

OSAudience::OSAudience(char *playerId) 
{
    _playerIds.push_back(playerId);
}

OSAudience::OSAudience(std::vector<char *> playerIds)
{
    _playerIds = playerIds;
}

OSAudience::OSAudience(std::vector<char *> includedSegments, std::vector<char *> excludedSegments)
{
    _includedSegments = includedSegments;
    _excludedSegments = excludedSegments;
}

bool OSAudience::validAudience()
{
    return (_playerIds.size() > 0 || _includedSegments.size() > 0);
}

void OSAudience::buildAudienceJson(OSCharBuffer *buf) 
{
    if (_playerIds.size() > 0) {
        buf->addText("\"include_player_ids\":");
        buildJsonArray(_playerIds, buf);
    } else {
        buf->addText("\"included_segments\":");
        buildJsonArray(_includedSegments, buf);

        if (_excludedSegments.size() > 0) {
            buf->addText("\"excluded_segments\":");
            buildJsonArray(_excludedSegments, buf);
        }
    }
}