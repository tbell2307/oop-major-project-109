#include "CropsToSell.h"
#include <iostream>

void CropsToSell::addParsnip(Parsnip p)
{
    harvestedParsnips.push_back(p);
    totalHarvested++;
    std::cout << "Total parsnips harvested: " << totalHarvested << std::endl;
}

void CropsToSell::showHarvestedParsnips()
{
    for (auto &parsnip : harvestedParsnips)
    {
    }
}

int CropsToSell::getTotalHarvested() const
{
    return totalHarvested;
}
