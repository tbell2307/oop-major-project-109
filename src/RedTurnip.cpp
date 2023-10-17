#include "include/RedTurnip.h"
#include <iostream>

sf::Texture RedTurnip::textureGrowing;
sf::Texture RedTurnip::textureMature;

RedTurnip::RedTurnip() : SeasonalCrop("Summer", 3)
{
    sellValue = 50;
    if (textureGrowing.getSize().x == 0 && textureGrowing.getSize().y == 0)
    {
        if (!textureGrowing.loadFromFile("assets/seeds.png"))
        {
            std::cout << "Error loading seeds.png" << std::endl;
        }
    }

    if (textureMature.getSize().x == 0 && textureMature.getSize().y == 0)
    {
        if (!textureMature.loadFromFile("assets/red_turnip0.png"))
        {
            std::cout << "Error loading red_turnip0.png" << std::endl;
        }
    }

    sprite.setTexture(textureGrowing);

    // Set scaling
    float scaleX = 2.4f;
    float scaleY = 2.4f;
    sprite.setScale(scaleX, scaleY);
}

RedTurnip::~RedTurnip()
{
}

sf::Vector2f RedTurnip::getPosition() const
{
    return sprite.getPosition();
}

void RedTurnip::harvest()
{
    sprite.setTexture(textureMature);
}

void RedTurnip::draw(sf::RenderWindow &window)
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
