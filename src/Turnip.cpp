#include "Turnip.h"
#include <iostream>

sf::Texture Turnip::textureGrowing;
sf::Texture Turnip::textureMature;

Turnip::Turnip() : SeasonalCrop("Spring"), daysSincePlanted(0), timesWatered(0), mature(false)
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
        if (!textureMature.loadFromFile("src/assets/turnip0.png"))
        {
            std::cout << "Error loading turnip0.png" << std::endl;
        }
    }

    sprite.setTexture(textureGrowing);

    sf::Vector2u textureSize = textureGrowing.getSize();
    float scaleX = static_cast<float>(50) / static_cast<float>(textureSize.x);
    float scaleY = static_cast<float>(50) / static_cast<float>(textureSize.y);
    sprite.setScale(scaleX, scaleY);
}

Turnip::~Turnip()
{
}

void Turnip::grow()
{
    ++daysSincePlanted;

    if (daysSincePlanted >= 4 && timesWatered >= 4 && !mature)
    {
        std::cout << "Turnip has matured!" << std::endl;
        sprite.setTexture(textureMature);
        mature = true;
    }
}

void Turnip::water()
{
    if (daysSincePlanted < 4 && !mature) // Only allow watering within the first 4 days and if not yet mature
    {
        ++timesWatered;
        std::cout << "Turnip has been watered " << timesWatered << " times." << std::endl;
    }
}

void Turnip::plant(int x, int y, bool isTileWet) // added an isTileWet flag
{
    sprite.setPosition(x, y);
    sprite.setTexture(textureGrowing);
    if (isTileWet)
    {
        timesWatered = 1; // Initialize to 1 if the tile is already wet
    }
}

sf::Vector2f Turnip::getPosition() const
{
    return sprite.getPosition();
}

void Turnip::harvest()
{
    std::cout << "Harvesting turnip with Spring-specific logic" << std::endl;
    // Here, you would change the state of the turnip, if necessary
    sprite.setTexture(textureMature);
}

void Turnip::draw(sf::RenderWindow &window)
{
    window.draw(sprite);
}
