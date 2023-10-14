#include "SeasonalCrop.h"
#include <iostream>

SeasonalCrop::SeasonalCrop(const std::string &preferredSeason) : preferredSeason(preferredSeason)
{
    // Constructor logic here
}

SeasonalCrop::~SeasonalCrop()
{
    // Destructor logic here
}

void SeasonalCrop::grow()
{
    std::cout << "Growing logic for " << preferredSeason << " crops" << std::endl;
}

void SeasonalCrop::harvest()
{
    std::cout << "Harvesting logic for " << preferredSeason << " crops" << std::endl;
}
