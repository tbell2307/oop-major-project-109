#include "include/Beetroot.h"
#include <iostream>

sf::Texture Beetroot::textureGrowing;
sf::Texture Beetroot::textureMature;

Beetroot::Beetroot() : SeasonalCrop("Spring", 10)
{
    sellValue = 300;
    if (textureGrowing.getSize().x == 0 && textureGrowing.getSize().y == 0)
    {
        if (!textureGrowing.loadFromFile("assets/seeds.png"))
        {
            std::cout << "Error loading seeds.png" << std::endl;
        }
    }

    if (textureMature.getSize().x == 0 && textureMature.getSize().y == 0)
    {
        if (!textureMature.loadFromFile("assets/beetroot0.png"))
        {
            std::cout << "Error loading beetroot0.png" << std::endl;
        }
    }

    sprite.setTexture(textureGrowing);

    // Set scaling
    float scaleX = 2.4f;
    float scaleY = 2.4f;
    sprite.setScale(scaleX, scaleY);
}

Beetroot::~Beetroot()
{
}

sf::Vector2f Beetroot::getPosition() const
{
    return sprite.getPosition();
}

void Beetroot::harvest()
{
    sprite.setTexture(textureMature);
}

void Beetroot::draw(sf::RenderWindow &window)
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
