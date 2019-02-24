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

bool OSAudience::requiresApiKey()
{
    return _includedSegments.size() > 0;
}

void OSAudience::validAudience(char **error)
{
    if (_playerIds.size() == 0 && _includedSegments.size() == 0)
        *error = "Audience must include at least one player ID or segment";
}

void OSAudience::buildAudienceJson(OSJSONBuilder &builder)
{
    if (_playerIds.size() > 0) {
        builder.addJSONArray("include_player_ids", _playerIds);
    } else {
        builder.addJSONArray("included_segments", _includedSegments);

        if (_excludedSegments.size() > 0)
            builder.addJSONArray("excluded_segments", _excludedSegments);
    }
}