#include "Parsnip.h"
#include <iostream>

sf::Texture Parsnip::textureGrowing;
sf::Texture Parsnip::textureMature;

Parsnip::Parsnip() : SeasonalCrop("Spring")
{
    // Load the textures if they have not been loaded yet
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

    sf::Vector2u textureSize = textureGrowing.getSize();
    float scaleX = static_cast<float>(50) / static_cast<float>(textureSize.x);
    float scaleY = static_cast<float>(50) / static_cast<float>(textureSize.y);
    sprite.setScale(scaleX, scaleY);
}

Parsnip::~Parsnip()
{
}

void Parsnip::grow()
{
    std::cout << "Parsnip is growing with Spring-specific logic" << std::endl;
    // Here, you would change the state of the parsnip, if necessary
    sprite.setTexture(textureGrowing);
}

void Parsnip::plant(int x, int y)
{
    sprite.setPosition(x, y);
    sprite.setTexture(textureGrowing);
}

sf::Vector2f Parsnip::getPosition() const
{
    return sprite.getPosition();
}

void Parsnip::harvest()
{
    std::cout << "Harvesting parsnip with Spring-specific logic" << std::endl;
    // Here, you would change the state of the parsnip, if necessary
    sprite.setTexture(textureMature);
}

void Parsnip::draw(sf::RenderWindow &window)
{
    window.draw(sprite);
}
