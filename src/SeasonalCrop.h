#ifndef SEASONALCROP_H
#define SEASONALCROP_H

#include "Crop.h"
#include <string>

class SeasonalCrop : public Crop
{
public:
    SeasonalCrop(const std::string &preferredSeason);
    virtual ~SeasonalCrop();

    void grow() override;
    void harvest() override;

private:
    std::string preferredSeason;
};

#endif