#include "include/Crop.h"
#include <iostream>

Crop::Crop() : mature(false)
{
    // Constructor logic here
}

Crop::~Crop()
{
    // Destructor logic here
}

void Crop::grow(const std::string &currentSeason)
{
    std::cout << "Generic crop growing logic" << std::endl;
}

void Crop::harvest()
{
    std::cout << "Generic crop harvesting logic" << std::endl;
}

void Crop::water()
{
    std::cout << "Generic watering logic" << std::endl;
}

void Crop::plant(int x, int y, bool isTileWet)
{
    std::cout << "Generic planting logic" << std::endl;
}

void Crop::draw(sf::RenderWindow &window)
{
    window.draw(sprite);
}

bool Crop::isMature() const
{
    return mature;
}

sf::Vector2f Crop::getPosition() const
{
    return sprite.getPosition();
}
