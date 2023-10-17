#include "Parsnip.h"
#include <iostream>

sf::Texture Parsnip::textureGrowing;
sf::Texture Parsnip::textureMature;

Parsnip::Parsnip() : SeasonalCrop("Spring")
{
    requiredWaterings = 4;

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

void Parsnip::grow()
{
    ++daysSincePlanted;

    if (timesWatered >= 4 && !mature)
    {
        std::cout << "Parsnip has matured!" << std::endl;
        sprite.setTexture(textureMature);
        mature = true;
    }
}

void Parsnip::water()
{
    if (!mature) // Only allow watering within the first 4 days and if not yet mature
    {
        ++timesWatered;
        std::cout << "Parsnip has been watered " << timesWatered << " times." << std::endl;
    }
}

void Parsnip::plant(int x, int y, bool isTileWet) // added an isTileWet flag
{
    sprite.setPosition(x, y);
    sprite.setTexture(textureGrowing);
    if (isTileWet)
    {
        timesWatered = 1; // Initialize to 1 if the tile is already wet
    }
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
