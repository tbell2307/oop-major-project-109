#ifndef BEETROOT_H
#define BEETROOT_H

#include <SFML/Graphics.hpp>
#include "SeasonalCrop.h"

class Beetroot : public SeasonalCrop
{
public:
    Beetroot();
    ~Beetroot();
    sf::Vector2f getPosition() const override;
    void harvest() override;
    void draw(sf::RenderWindow &window) override;
    bool isMature() const override { return mature; }
    static sf::Texture textureGrowing;
    static sf::Texture textureMature;
    std::string getType() const override
    {
        return "Beetroot";
    }
};

#endif
