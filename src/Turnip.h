#ifndef TURNIP_H
#define TURNIP_H

#include <SFML/Graphics.hpp>
#include "SeasonalCrop.h"

class Turnip : public SeasonalCrop
{
public:
    Turnip();
    ~Turnip();
    void grow() override;
    void water();
    void plant(int x, int y, bool isTileWet);
    sf::Vector2f getPosition() const;
    void harvest() override;
    void draw(sf::RenderWindow &window);
    bool isMature() const { return mature; }
    static sf::Texture textureGrowing;
    static sf::Texture textureMature;
    std::string getType() const override
    {
        return "Turnip";
    }

private:
    int daysSincePlanted;
    int timesWatered;
    bool mature;
    sf::Sprite sprite;
};

#endif
