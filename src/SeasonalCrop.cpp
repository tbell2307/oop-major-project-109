#include "include/SeasonalCrop.h"
#include <iostream>

SeasonalCrop::SeasonalCrop(const std::string &preferredSeason, int requiredWaterings)
    : preferredSeason(preferredSeason), requiredWaterings(requiredWaterings), daysSincePlanted(0), timesWatered(0)
{
}
SeasonalCrop::~SeasonalCrop()
{
}

void SeasonalCrop::grow(const std::string &currentSeason)
{
    ++daysSincePlanted;

    int adjustedRequiredWaterings = requiredWaterings;

    // Check if the current season is not the preferred season for the crop
    if (currentSeason != preferredSeason)
    {
        adjustedRequiredWaterings = requiredWaterings * 4;
    }
    else
    {
        adjustedRequiredWaterings = requiredWaterings * 2;
    }

    if (timesWatered >= adjustedRequiredWaterings && !mature)
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
    timesWatered = isTileWet ? 1 : 0;
    mature = false;
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

int SeasonalCrop::getRequiredWaterings() const
{
    return requiredWaterings;
}