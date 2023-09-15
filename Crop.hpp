#pragma once

#include <string>

class Crop
{
private:
    std::string m_name;
    std::string m_harvest_season;
    int m_growing_time;
    bool m_watered = false;
    bool m_fertilised = false;
    bool m_will_survive = true;
    bool m_harvested = false;

public:
    Crop();
    Crop(std::string name,
         std::string harvest_season,
         int growing_time);
    ~Crop();
};
