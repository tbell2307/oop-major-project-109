#include "include/Farm.h"
#include <cmath>

Farm::Farm()
{
    if (!texture.loadFromFile("src/assets/grass.jpeg") ||
        !soilTexture.loadFromFile("src/assets/soil.png") ||
        !wetSoilTexture.loadFromFile("src/assets/wetSoil.png"))
    {
        exit(-1);
    }
    tileSize = 50;
    initializeTiles(tileSize);
}

void Farm::initializeTiles(int tileSize)
{
    for (int i = 0; i < 12; ++i)
    {
        for (int j = 0; j < 12; ++j)
        {
            tiles[i][j].setSize(sf::Vector2f(tileSize, tileSize));
            tiles[i][j].setPosition(i * tileSize, j * tileSize + 52);
            tiles[i][j].setTexture(&texture);
        }
    }
}

void Farm::draw(sf::RenderWindow &window)
{
    for (int i = 0; i < 12; ++i)
    {
        for (int j = 0; j < 12; ++j)
        {
            window.draw(tiles[i][j]);
        }
    }
}

const sf::Texture *Farm::getSoilTexture()
{
    return &soilTexture;
}

const sf::Texture *Farm::getWetSoilTexture()
{
    return &wetSoilTexture;
}

void Farm::setTileTexture(int x, int y, const sf::Texture *texture)
{
    tiles[x][y].setTexture(texture);
}

sf::Vector2i Farm::getClickedTile(int x, int y)
{
    int tileX = x / tileSize;
    int tileY = (y - 52) / tileSize;
    return sf::Vector2i(tileX, tileY);
}

const sf::Texture *Farm::getTileTexture(int x, int y)
{
    return tiles[x][y].getTexture();
}
