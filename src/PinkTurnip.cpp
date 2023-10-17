#include "PinkTurnip.h"
#include <iostream>

sf::Texture PinkTurnip::textureGrowing;
sf::Texture PinkTurnip::textureMature;

PinkTurnip::PinkTurnip() : SeasonalCrop("Summer", 5)
{
    sellValue = 90;
    if (textureGrowing.getSize().x == 0 && textureGrowing.getSize().y == 0)
    {
        if (!textureGrowing.loadFromFile("src/assets/seeds.png"))
        {
            std::cout << "Error loading seeds.png" << std::endl;
        }
    }

    if (textureMature.getSize().x == 0 && textureMature.getSize().y == 0)
    {
        if (!textureMature.loadFromFile("src/assets/pink_turnip0.png"))
        {
            std::cout << "Error loading pink_turnip0.png" << std::endl;
        }
    }

    sprite.setTexture(textureGrowing);

    // Set scaling
    sf::Vector2u textureSize = sprite.getTexture()->getSize();
    float scaleX = 2.4f;
    float scaleY = 2.4f;
    sprite.setScale(scaleX, scaleY);
}

PinkTurnip::~PinkTurnip()
{
}

sf::Vector2f PinkTurnip::getPosition() const
{
    return sprite.getPosition();
}

void PinkTurnip::harvest()
{
    sprite.setTexture(textureMature);
}

void PinkTurnip::draw(sf::RenderWindow &window)
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
