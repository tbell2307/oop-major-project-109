#ifndef PARSNIP_H
#define PARSNIP_H

#include <SFML/Graphics.hpp>
#include "SeasonalCrop.h"

class Parsnip : public SeasonalCrop
{
public:
    Parsnip();
    ~Parsnip();
    sf::Vector2f getPosition() const override;
    void harvest() override;
    void draw(sf::RenderWindow &window) override;
    bool isMature() const override { return mature; }
    static sf::Texture textureGrowing;
    static sf::Texture textureMature;
    std::string getType() const override
    {
        return "Parsnip";
    }
};

#endif
