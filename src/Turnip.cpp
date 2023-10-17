#include "include/Turnip.h"
#include <iostream>

sf::Texture Turnip::textureGrowing;
sf::Texture Turnip::textureMature;

Turnip::Turnip() : SeasonalCrop("Spring", 6)
{
    sellValue = 110;
    if (textureGrowing.getSize().x == 0 && textureGrowing.getSize().y == 0)
    {
        if (!textureGrowing.loadFromFile("src/assets/seeds.png"))
        {
            std::cout << "Error loading seeds.png" << std::endl;
        }
    }

    if (textureMature.getSize().x == 0 && textureMature.getSize().y == 0)
    {
        if (!textureMature.loadFromFile("src/assets/turnip0.png"))
        {
            std::cout << "Error loading turnip0.png" << std::endl;
        }
    }

    sprite.setTexture(textureGrowing);

    // Set scaling
    float scaleX = 2.4f;
    float scaleY = 2.4f;
    sprite.setScale(scaleX, scaleY);
}

Turnip::~Turnip()
{
}

sf::Vector2f Turnip::getPosition() const
{
    return sprite.getPosition();
}

void Turnip::harvest()
{
    sprite.setTexture(textureMature);
}

void Turnip::draw(sf::RenderWindow &window)
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
