#ifndef CROPS_TO_SELL_H
#define CROPS_TO_SELL_H

#include <map>
#include <vector>
#include <string>
#include "Crop.h" // Assuming this is your general Crop header

class CropsToSell
{
private:
    std::map<std::string, std::vector<Crop *>> harvestedCrops; // Mapping from crop type to a vector of harvested crops

public:
    CropsToSell() {}

    void addCrop(Crop *p);
    void showHarvestedCrops();
    int getTotalHarvested() const;
    int getTotalHarvestedOfType(const std::string &type) const;
};

#endif
