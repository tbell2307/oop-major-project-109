#include "Crop.hpp"

Crop::Crop()
{
}

Crop::Crop(std::string name,
         std::string harvest_season,
         int growing_time)
    : m_growing_time(growing_time), m_name(name), m_harvest_season(harvest_season)
{
}

Crop::~Crop()
{
}