#ifndef CROPS_TO_SELL_H
#define CROPS_TO_SELL_H

#include <vector>
#include "Parsnip.h"

class CropsToSell
{
private:
    std::vector<Parsnip> harvestedParsnips;
    int totalHarvested; 

public:
    CropsToSell() : totalHarvested(0) {}

    void addParsnip(Parsnip p);
    void showHarvestedParsnips();
    int getTotalHarvested() const;
};

#endif
