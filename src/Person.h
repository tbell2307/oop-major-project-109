#ifndef PERSON_H
#define PERSON_H
#include <SFML/Graphics.hpp>

class Person
{
public:
    Person(const std::string &texturePath, int tileSize);
    ~Person();

    void setPosition(float x, float y);
    sf::Vector2f getPosition() const;

    void setScale(int tileSize);
    sf::Sprite &getSprite();

private:
    sf::Texture personTexture;
    sf::Sprite person;
};

#endif // PERSON_H
