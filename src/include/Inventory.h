#ifndef INVENTORY_H
#define INVENTORY_H

#include <SFML/Graphics.hpp>

class Inventory
{
public:
    Inventory();
    void draw(sf::RenderWindow &window);
    void setSelection(int index);
    int getSelectedInventoryIndex() const { return selectedInventoryIndex; }

private:
    sf::RectangleShape inventory[10];
    sf::RectangleShape inventoryBackgroundTiles[13][2];
    sf::Texture inventoryTexture;
    sf::Texture inventoryBackgroundTexture;
    int selectedInventoryIndex;
};

#endif
