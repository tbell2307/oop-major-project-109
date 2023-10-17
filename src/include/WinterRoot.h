#ifndef WINTER_ROOT_H
#define WINTER_ROOT_H

#include <SFML/Graphics.hpp>
#include "SeasonalCrop.h"

class WinterRoot : public SeasonalCrop
{
public:
    WinterRoot();
    ~WinterRoot();
    sf::Vector2f getPosition() const override;
    void harvest() override;
    void draw(sf::RenderWindow &window) override;
    bool isMature() const override { return mature; }
    static sf::Texture textureGrowing;
    static sf::Texture textureMature;
    std::string getType() const override
    {
        return "WinterRoot";
    }
};

#endif
