#ifndef GREEN_TURNIP_H
#define GREEN_TURNIP_H

#include <SFML/Graphics.hpp>
#include "SeasonalCrop.h"

class GreenTurnip : public SeasonalCrop
{
public:
    GreenTurnip();
    ~GreenTurnip();
    sf::Vector2f getPosition() const override;
    void harvest() override;
    void draw(sf::RenderWindow &window) override;
    bool isMature() const override { return mature; }
    static sf::Texture textureGrowing;
    static sf::Texture textureMature;
    std::string getType() const override
    {
        return "GreenTurnip";
    }
};

#endif
