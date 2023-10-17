#include "Parsnip.h"
#include <iostream>

sf::Texture Parsnip::textureGrowing;
sf::Texture Parsnip::textureMature;

Parsnip::Parsnip() : SeasonalCrop("Spring", 4)
{
    sellValue = 30;
    if (textureGrowing.getSize().x == 0 && textureGrowing.getSize().y == 0)
    {
        if (!textureGrowing.loadFromFile("src/assets/seeds.png"))
        {
            std::cout << "Error loading seeds.png" << std::endl;
        }
    }

    if (textureMature.getSize().x == 0 && textureMature.getSize().y == 0)
    {
        if (!textureMature.loadFromFile("src/assets/parsnip0.png"))
        {
            std::cout << "Error loading parsnip0.png" << std::endl;
        }
    }

    sprite.setTexture(textureGrowing);

    // Set scaling
    sf::Vector2u textureSize = sprite.getTexture()->getSize();
    float scaleX = 2.4f;
    float scaleY = 2.4f;
    sprite.setScale(scaleX, scaleY);
}

Parsnip::~Parsnip()
{
}

sf::Vector2f Parsnip::getPosition() const
{
    return sprite.getPosition();
}

void Parsnip::harvest()
{
    sprite.setTexture(textureMature);
}

void Parsnip::draw(sf::RenderWindow &window)
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
