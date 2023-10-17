#include "include/WinterRoot.h"
#include <iostream>

sf::Texture WinterRoot::textureGrowing;
sf::Texture WinterRoot::textureMature;

WinterRoot::WinterRoot() : SeasonalCrop("Winter", 8)
{
    sellValue = 170;
    if (textureGrowing.getSize().x == 0 && textureGrowing.getSize().y == 0)
    {
        if (!textureGrowing.loadFromFile("src/assets/seeds.png"))
        {
            std::cout << "Error loading seeds.png" << std::endl;
        }
    }

    if (textureMature.getSize().x == 0 && textureMature.getSize().y == 0)
    {
        if (!textureMature.loadFromFile("src/assets/winter_root0.png"))
        {
            std::cout << "Error loading winter_root0.png" << std::endl;
        }
    }

    sprite.setTexture(textureGrowing);

    // Set scaling
    sf::Vector2u textureSize = sprite.getTexture()->getSize();
    float scaleX = 2.4f;
    float scaleY = 2.4f;
    sprite.setScale(scaleX, scaleY);
}

WinterRoot::~WinterRoot()
{
}

sf::Vector2f WinterRoot::getPosition() const
{
    return sprite.getPosition();
}

void WinterRoot::harvest()
{
    sprite.setTexture(textureMature);
}

void WinterRoot::draw(sf::RenderWindow &window)
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
