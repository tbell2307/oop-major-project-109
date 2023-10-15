#ifndef PARSNIP_H
#define PARSNIP_H

#include <SFML/Graphics.hpp>
#include "SeasonalCrop.h"

class Parsnip : public SeasonalCrop
{
public:
    Parsnip();
    ~Parsnip();
    void grow();
    void water();
    void plant(int x, int y);
    sf::Vector2f getPosition() const;
    void harvest();
    void draw(sf::RenderWindow &window);
    bool isMature() const { return mature; }
    static sf::Texture textureGrowing;
    static sf::Texture textureMature;

private:
    int daysSincePlanted;
    int timesWatered;
    bool mature;
    sf::Sprite sprite;
};

#endif
