#ifndef SEASONALCROP_H
#define SEASONALCROP_H

#include "Crop.h"
#include <string>
#include <SFML/Graphics.hpp>

class SeasonalCrop : public Crop
{
public:
    SeasonalCrop(const std::string &preferredSeason, int requiredWaterings);
    virtual ~SeasonalCrop();
    virtual void grow(const std::string &currentSeason) override;
    virtual void water() override;
    virtual void plant(int x, int y, bool isTileWet) override;
    virtual void harvest() override;
    virtual int getRequiredWaterings() const override;

protected:
    std::string preferredSeason;
    int daysSincePlanted;
    int timesWatered;
    int requiredWaterings;
    sf::Sprite sprite;
    sf::Texture textureGrowing;
    sf::Texture textureMature;
};

#endif