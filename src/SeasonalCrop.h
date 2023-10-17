#ifndef SEASONALCROP_H
#define SEASONALCROP_H

#include "Crop.h"
#include <string>
#include <SFML/Graphics.hpp>

class SeasonalCrop : public Crop
{
public:
    SeasonalCrop(const std::string &preferredSeason);
    virtual ~SeasonalCrop();
    virtual void grow() override;
    virtual void water();
    virtual void plant(int x, int y, bool isTileWet);
    virtual void harvest() override;

protected:
    std::string preferredSeason;
    int daysSincePlanted;
    int timesWatered;
    bool mature;
    int requiredWaterings;
    sf::Sprite sprite;
    sf::Texture textureGrowing;
    sf::Texture textureMature;
};

#endif