#include "include/GreenTurnip.h"
#include <iostream>

sf::Texture GreenTurnip::textureGrowing;
sf::Texture GreenTurnip::textureMature;

GreenTurnip::GreenTurnip() : SeasonalCrop("Autmun", 3)
{
    sellValue = 50;
    if (textureGrowing.getSize().x == 0 && textureGrowing.getSize().y == 0)
    {
        if (!textureGrowing.loadFromFile("src/assets/seeds.png"))
        {
            std::cout << "Error loading seeds.png" << std::endl;
        }
    }

    if (textureMature.getSize().x == 0 && textureMature.getSize().y == 0)
    {
        if (!textureMature.loadFromFile("src/assets/green_turnip0.png"))
        {
            std::cout << "Error loading green_turnip0.png" << std::endl;
        }
    }

    sprite.setTexture(textureGrowing);

    // Set scaling
    sf::Vector2u textureSize = sprite.getTexture()->getSize();
    float scaleX = 2.4f;
    float scaleY = 2.4f;
    sprite.setScale(scaleX, scaleY);
}

GreenTurnip::~GreenTurnip()
{
}

sf::Vector2f GreenTurnip::getPosition() const
{
    return sprite.getPosition();
}

void GreenTurnip::harvest()
{
    sprite.setTexture(textureMature);
}

void GreenTurnip::draw(sf::RenderWindow &window)
{
    if (isMature())
    {
        sprite.setTexture(textureMature);
    }
    else
    {
        sprite.setTexture(textureGrowing);
    }

    window.draw(sprite);
}
