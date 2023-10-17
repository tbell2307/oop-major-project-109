#ifndef FARM_H
#define FARM_H
#include <SFML/Graphics.hpp>

class Farm
{
public:
    Farm();
    void initializeTiles(int tileSize);
    void draw(sf::RenderWindow &window);
    const sf::Texture *getSoilTexture();
    const sf::Texture *getWetSoilTexture();
    void setTileTexture(int x, int y, const sf::Texture *texture);
    sf::Vector2i getClickedTile(int x, int y);
    const sf::Texture *getTileTexture(int x, int y);

private:
    sf::Texture texture;
    sf::Texture soilTexture;
    sf::Texture wetSoilTexture;
    sf::RectangleShape tiles[12][12];
    int tileSize;
};

#endif