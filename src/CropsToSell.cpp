#include "CropsToSell.h"
#include <iostream>

void CropsToSell::addCrop(Crop *p)
{
    std::string type = p->getType(); // Assuming your Crop class has a getType() method
    harvestedCrops[type].push_back(p);
    std::cout << "Total " << type << " harvested: " << harvestedCrops[type].size() << std::endl;
}

void CropsToSell::showHarvestedCrops()
{
    for (const auto &[type, crops] : harvestedCrops)
    {
        std::cout << "Type: " << type << ", Count: " << crops.size() << std::endl;
    }
}

int CropsToSell::getTotalHarvested() const
{
    int total = 0;
    for (const auto &[type, crops] : harvestedCrops)
    {
        total += crops.size();
    }
    return total;
}

int CropsToSell::getTotalHarvestedOfType(const std::string &type) const
{
    if (harvestedCrops.find(type) != harvestedCrops.end())
    {
        return harvestedCrops.at(type).size();
    }
    return 0;
}
