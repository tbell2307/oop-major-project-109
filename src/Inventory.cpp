#include "Inventory.h"

Inventory::Inventory()
    : selectedInventoryIndex(-1) // Initialize selectedInventoryIndex here
{
    // Load textures
    if (!inventoryTexture.loadFromFile("src/assets/inventory.jpeg") ||
        !inventoryBackgroundTexture.loadFromFile("src/assets/inventory-background.jpeg"))
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

    int inventorySize = 10;
    int inventoryTileSize = 50;
    // Manually set the starting X position
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
}

void Inventory::setSelection(int index)
{
    if (index < 0 || index >= 10)
    {
        return; // Invalid index
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
