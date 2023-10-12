#include "Person.h"

Person::Person(const std::string &texturePath, int tileSize)
{
    if (!personTexture.loadFromFile(texturePath))
    {
        // handle error
    }

    person.setTexture(personTexture);
    setScale(tileSize);
}

Person::~Person()
{
}

void Person::setPosition(float x, float y)
{
    person.setPosition(x, y);
}

sf::Vector2f Person::getPosition() const
{
    return person.getPosition();
}

void Person::setScale(int tileSize)
{
    sf::Vector2u textureSize = personTexture.getSize();
    float scaleX = static_cast<float>(tileSize) / static_cast<float>(textureSize.x);
    float scaleY = static_cast<float>(tileSize) / static_cast<float>(textureSize.y);
    person.setScale(scaleX, scaleY);
}

sf::Sprite &Person::getSprite()
{
    return person;
}
