#ifndef CARROT_H
#define CARROT_H

#include <SFML/Graphics.hpp>
#include "SeasonalCrop.h"

class Carrot : public SeasonalCrop
{
public:
    Carrot();
    ~Carrot();
    sf::Vector2f getPosition() const override;
    void harvest() override;
    void draw(sf::RenderWindow &window) override;
    bool isMature() const override { return mature; }
    static sf::Texture textureGrowing;
    static sf::Texture textureMature;
    std::string getType() const override
    {
        return "Carrot";
    }
};

#endif
