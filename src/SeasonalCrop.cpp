#include "SeasonalCrop.h"
#include <iostream>

SeasonalCrop::SeasonalCrop(const std::string &preferredSeason) : preferredSeason(preferredSeason), daysSincePlanted(0), timesWatered(0), mature(false)
{
}
SeasonalCrop::~SeasonalCrop()
{
    // Destructor logic here
}

void SeasonalCrop::grow()
{
    ++daysSincePlanted;
    if (timesWatered >= requiredWaterings && !mature)
    {
        sprite.setTexture(textureMature);
        mature = true;
    }
}

void SeasonalCrop::water()
{
    if (!mature)
    {
        ++timesWatered;
    }
}

void SeasonalCrop::plant(int x, int y, bool isTileWet)
{
    sprite.setPosition(x, y);
    sprite.setTexture(textureGrowing);
    if (isTileWet)
    {
        timesWatered = 1;
    }
}

void SeasonalCrop::harvest()
{
    if (mature)
    {
        std::cout << "Harvesting " << preferredSeason << "-specific crop" << std::endl;
    }
    else
    {
        std::cout << "Cannot harvest. The crop is not yet mature." << std::endl;
    }
}
