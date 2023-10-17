#include "include/Carrot.h"
#include <iostream>

sf::Texture Carrot::textureGrowing;
sf::Texture Carrot::textureMature;

Carrot::Carrot() : SeasonalCrop("Autumn", 7)
{
    sellValue = 140;
    if (textureGrowing.getSize().x == 0 && textureGrowing.getSize().y == 0)
    {
        if (!textureGrowing.loadFromFile("src/assets/seeds.png"))
        {
            std::cout << "Error loading seeds.png" << std::endl;
        }
    }

    if (textureMature.getSize().x == 0 && textureMature.getSize().y == 0)
    {
        if (!textureMature.loadFromFile("src/assets/carrot0.png"))
        {
            std::cout << "Error loading carrot0.png" << std::endl;
        }
    }

    sprite.setTexture(textureGrowing);

    // Set scaling
    sf::Vector2u textureSize = sprite.getTexture()->getSize();
    float scaleX = 2.4f;
    float scaleY = 2.4f;
    sprite.setScale(scaleX, scaleY);
}

Carrot::~Carrot()
{
}

sf::Vector2f Carrot::getPosition() const
{
    return sprite.getPosition();
}

void Carrot::harvest()
{
    sprite.setTexture(textureMature);
}

void Carrot::draw(sf::RenderWindow &window)
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
