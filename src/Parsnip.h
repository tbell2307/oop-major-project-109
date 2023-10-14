#ifndef PARSNIP_H
#define PARSNIP_H

#include <SFML/Graphics.hpp>
#include "SeasonalCrop.h"

class Parsnip : public SeasonalCrop
{
public:
    Parsnip();
    ~Parsnip();

    static sf::Texture textureGrowing;
    static sf::Texture textureMature;

    void grow() override;
    void harvest() override;
    void draw(sf::RenderWindow &window);
    void plant(int x, int y);
    sf::Vector2f getPosition() const;

private:
    sf::Sprite sprite;
};

#endif
