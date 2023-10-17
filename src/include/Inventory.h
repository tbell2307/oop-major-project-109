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
    int getCropCount(int index);
    void decrementCropCount(int index);
    void incrementCropCount(int index);
    int getCropBuyPrice(int index) const
    {
        return CropBuyPrice.at(index);
    }

    void setCropBuyPrice(int index, int price)
    {
        CropBuyPrice[index] = price;
    }

private:
    sf::RectangleShape inventory[10];
    sf::RectangleShape inventoryBackgroundTiles[13][2];
    sf::Texture inventoryTexture;
    sf::Texture inventoryBackgroundTexture;
    int selectedInventoryIndex;
    std::map<int, int> cropCount;
    std::map<int, int> CropBuyPrice;
};

#endif
