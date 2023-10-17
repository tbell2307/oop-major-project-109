#include "include/Inventory.h"
#include <iostream>

Inventory::Inventory()
    : selectedInventoryIndex(-1)
{
    cropCount[2] = 5;
    cropCount[3] = 5;
    cropCount[4] = 0;
    cropCount[5] = 0;
    cropCount[6] = 0;
    cropCount[7] = 0;
    cropCount[8] = 0;
    cropCount[9] = 0;

    CropBuyPrice[2] = 20;
    CropBuyPrice[3] = 30;
    CropBuyPrice[4] = 40;
    CropBuyPrice[5] = 50;
    CropBuyPrice[6] = 60;
    CropBuyPrice[7] = 70;
    CropBuyPrice[8] = 80;
    CropBuyPrice[9] = 90;
    // Load textures
    if (!inventoryTexture.loadFromFile("assets/inventory.jpeg") ||
        !inventoryBackgroundTexture.loadFromFile("assets/inventory-background.jpeg"))
    {
        throw std::runtime_error("Failed to load textures");
    }

    int inventoryBackgroundStartY = 657;
    int inventoryBackgroundTileSize = 50;

    for (int i = 0; i < 13; ++i)
    {
        for (int j = 0; j < 2; ++j)
        {
            inventoryBackgroundTiles[i][j].setSize(sf::Vector2f(inventoryBackgroundTileSize, inventoryBackgroundTileSize));
            inventoryBackgroundTiles[i][j].setPosition(i * inventoryBackgroundTileSize, inventoryBackgroundStartY + j * inventoryBackgroundTileSize); // No extra pixels
            inventoryBackgroundTiles[i][j].setTexture(&inventoryBackgroundTexture);
        }
    }

    int startX = 42;
    int startY = 625;

    // Initialise the inventory bar
    for (int i = 0; i < 10; ++i)
    {
        inventory[i].setSize(sf::Vector2f(50, 50));
        inventory[i].setPosition(startX + i * 52, startY + 52);
        inventory[i].setTexture(&inventoryTexture);
        inventory[i].setOutlineColor(sf::Color::Black);
        inventory[i].setOutlineThickness(2);
    }
}

void Inventory::draw(sf::RenderWindow &window)
{
    // Draw background tiles
    for (int i = 0; i < 13; ++i)
    {
        for (int j = 0; j < 2; ++j)
        {
            window.draw(inventoryBackgroundTiles[i][j]);
        }
    }

    // Draw inventory slots
    for (int i = 0; i < 10; ++i)
    {
        window.draw(inventory[i]);
    }

    // Redraw the selected inventory item to bring its border to the top
    if (selectedInventoryIndex != -1)
    {
        window.draw(inventory[selectedInventoryIndex]);
    }

    sf::Font font; // Font for the text
    if (!font.loadFromFile("assets/font.ttf"))
    {
        std::cout << "Failed to load font" << std::endl;
    }

    for (auto &[index, count] : cropCount)
    {
        sf::Text countText;
        countText.setFont(font); // Set the font
        countText.setString(std::to_string(count));

        // Original Position
        int posX = index * 52 + 42;
        int posY = 625 + 52;
        countText.setPosition(posX, posY);

        countText.setCharacterSize(16);
        countText.setFillColor(sf::Color::White);

        // Draw the text
        window.draw(countText);
    }
}

void Inventory::setSelection(int index)
{
    if (index < 0 || index >= 10)
    {
        return;
    }

    // Reset previous selection border color
    if (selectedInventoryIndex != -1)
    {
        inventory[selectedInventoryIndex].setOutlineColor(sf::Color::Black);
    }

    // Set the new selection index
    selectedInventoryIndex = index;

    // Update border color
    inventory[selectedInventoryIndex].setOutlineColor(sf::Color::White);
}

int Inventory::getCropCount(int index)
{
    return cropCount[index];
}

void Inventory::decrementCropCount(int index)
{
    if (cropCount[index] > 0)
        cropCount[index]--;
}

void Inventory::incrementCropCount(int index)
{
    cropCount[index]++;
}
