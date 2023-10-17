#include "Parsnip.h"
#include <iostream>

<<<<<<< HEAD
sf::Texture Parsnip::textureGrowing;
sf::Texture Parsnip::textureMature;

Parsnip::Parsnip() : SeasonalCrop("Spring")
{
    requiredWaterings = 4;
=======
//constructor
Parsnip::Parsnip() : m_name("Parsnip"), m_sellprice(35.00), m_seedprice(20.00), m_growing_time(4), m_decay_time(2) {}
>>>>>>> develop

    if (textureGrowing.getSize().x == 0 && textureGrowing.getSize().y == 0)
    {
        if (!textureGrowing.loadFromFile("src/assets/seeds.png"))
        {
            std::cout << "Error loading seeds.png" << std::endl;
        }
    }

<<<<<<< HEAD
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
    if (!mature)
    {
        ++timesWatered;
        std::cout << "Parsnip has been watered " << timesWatered << " times." << std::endl;
    }
}

void Parsnip::plant(int x, int y, bool isTileWet)
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
    sprite.setTexture(textureMature);
}

void Parsnip::draw(sf::RenderWindow &window)
{
    window.draw(sprite);
=======
//get the name
std::string Parsnip::getName(){
    return m_name;
}

//get the sell price
double Parsnip::getSellPrice() {
    return m_sellprice;
}

//get the seed price
double Parsnip::getSeedPrice() {
    return m_seedprice;
}

//get the growing time
int Parsnip::getGrowingTime() {
    return m_growing_time;
}

//get the decay time
int Parsnip::getDecayTime() {
    return m_decay_time;
}

//set the X-coordinate
void Parsnip::setX(int x) {
    X = x;
}

//get the X-coordinate
int Parsnip::getX() {
    return X;
}

//set the Y-coordinate
void Parsnip::setY(int y) {
    Y = y;
}

//get the Y-coordinate
int Parsnip::getY() {
    return Y;
>>>>>>> develop
}
