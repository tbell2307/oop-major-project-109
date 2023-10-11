#include <SFML/Graphics.hpp>
#include <iostream>

int main()
{
    /////////////////////////////
    // Initialise the textures //
    /////////////////////////////

    // Create the window
    sf::RenderWindow window(sf::VideoMode(600, 755), "My Farm");

    // Load textures
    sf::Texture texture;
    if (!texture.loadFromFile("src/assets/grass.jpeg"))
    {
        return -1;
    }

    sf::Texture soilTexture;
    if (!soilTexture.loadFromFile("src/assets/soil.png"))
    {
        return -1;
    }

    sf::Texture pathTexture;
    if (!pathTexture.loadFromFile("src/assets/path.jpeg"))
    {
        return -1;
    }

    sf::Texture inventoryTexture;
    if (!inventoryTexture.loadFromFile("src/assets/inventory.jpeg"))
    {
        return -1;
    }

    sf::Texture waterTexture;
    if (!waterTexture.loadFromFile("src/assets/water.jpeg"))
    {
        return -1;
    }

    sf::Texture houseTexture;
    if (!houseTexture.loadFromFile("src/assets/house.png"))
    {
        return -1;
    }

    sf::Texture hoeIconTexture;
    if (!hoeIconTexture.loadFromFile("src/assets/hoe.png"))
    {
        return -1;
    }

    sf::Sprite hoeIcon;
    hoeIcon.setTexture(hoeIconTexture);

    sf::Vector2u textureSizeHoe = hoeIconTexture.getSize();
    float scaleXHoe = static_cast<float>(50) / static_cast<float>(textureSizeHoe.x);
    float scaleYHoe = static_cast<float>(50) / static_cast<float>(textureSizeHoe.y);
    hoeIcon.setScale(scaleXHoe, scaleYHoe);

    // Position it on the first inventory slot
    hoeIcon.setPosition(45, 677);

    sf::Texture wateringCanTextures[5];
    for (int i = 1; i <= 5; ++i)
    {
        if (!wateringCanTextures[i - 1].loadFromFile("src/assets/wateringcan" + std::to_string(i) + ".png"))
        {
            return -1;
        }
    }

    int wateringCanClicks = 0;
    int wateringCanTextureIndex = 0; // Start with the first texture

    sf::Sprite wateringCanIcon;
    wateringCanIcon.setTexture(wateringCanTextures[0]);

    sf::Vector2u textureSizeCan = wateringCanTextures[0].getSize();
    float scaleXCan = static_cast<float>(65) / static_cast<float>(textureSizeCan.x);
    float scaleYCan = static_cast<float>(65) / static_cast<float>(textureSizeCan.y);
    wateringCanIcon.setScale(scaleXCan, scaleYCan);

    // Position it on the first inventory slot
    wateringCanIcon.setPosition(92, 670);

    // Watering can highlight
    sf::RectangleShape blueBorder(sf::Vector2f(50, 50));
    blueBorder.setFillColor(sf::Color::Transparent);
    blueBorder.setOutlineThickness(1);
    blueBorder.setOutlineColor(sf::Color::Blue);

    sf::RectangleShape waterTiles[12];

    for (int i = 0; i < 12; ++i)
    {
        waterTiles[i].setSize(sf::Vector2f(50, 50));
        waterTiles[i].setPosition(i * 50, 0);

        if (i == 0 || i == 1 || i == 2)
        {
            waterTiles[i].setTexture(&waterTexture);
        }
        else if (i == 8 || i == 9 || i == 10)
        {
            waterTiles[i].setTexture(&houseTexture);
        }
        else
        {
            waterTiles[i].setTexture(&pathTexture);
        }
    }

    sf::Texture inventoryBackgroundTexture;
    if (!inventoryBackgroundTexture.loadFromFile("src/assets/inventory-background.jpeg"))
    {
        return -1;
    }

    int inventoryBackgroundStartY = 657;
    int inventoryBackgroundTileSize = 50;

    int selectedInventoryIndex = -1;

    sf::RectangleShape inventoryBackgroundTiles[13][2];

    for (int i = 0; i < 13; ++i)
    {
        for (int j = 0; j < 2; ++j)
        {
            inventoryBackgroundTiles[i][j].setSize(sf::Vector2f(inventoryBackgroundTileSize, inventoryBackgroundTileSize));
            inventoryBackgroundTiles[i][j].setPosition(i * inventoryBackgroundTileSize, inventoryBackgroundStartY + j * inventoryBackgroundTileSize); // No extra pixels
            inventoryBackgroundTiles[i][j].setTexture(&inventoryBackgroundTexture);
        }
    }

    // Define tile size
    int tileSize = 50;
    sf::RectangleShape tiles[12][12];

    bool highlightedTiles[12][12] = {{false}};

    // Loop for rendering farm tiles
    for (int i = 0; i < 12; ++i)
    {
        for (int j = 0; j < 12; ++j)
        {
            tiles[i][j].setSize(sf::Vector2f(tileSize, tileSize));
            tiles[i][j].setPosition(i * (tileSize), j * (tileSize) + 52);

            if (i == 0 || i == 11 || j == 0 || j == 11)
            {
                // Set the outside ring as a path texture
                tiles[i][j].setTexture(&pathTexture);
            }
            else
            {
                // Set the tiles to be grass textured
                tiles[i][j].setTexture(&texture);
            }
        }
    }

    int inventorySize = 10;
    sf::RectangleShape inventory[inventorySize];
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

    // Render person sprite
    sf::Texture personTexture;
    if (!personTexture.loadFromFile("src/assets/person.png"))
    {
        return -1;
    }

    // Define farmer
    sf::Sprite person;
    person.setTexture(personTexture);

    // Scale down to fit a single tile
    sf::Vector2u textureSize = personTexture.getSize();
    float scaleX = static_cast<float>(tileSize) / static_cast<float>(textureSize.x);
    float scaleY = static_cast<float>(tileSize) / static_cast<float>(textureSize.y);
    person.setScale(scaleX, scaleY);

    // Set initial position of farmer to be centered in tile (1, 1)
    person.setPosition(52 + 1, 52 + 1);

    // Create a square using the grass
    sf::RectangleShape rectangle(sf::Vector2f(50, 50));
    rectangle.setTexture(&texture);

    // Create grid lines
    sf::RectangleShape vLine(sf::Vector2f(2, 510)); // vertical
    sf::RectangleShape hLine(sf::Vector2f(510, 2)); // horizontal
    vLine.setFillColor(sf::Color::White);
    hLine.setFillColor(sf::Color::White);

    /////////////////////////////
    // Logic for button inputs //
    /////////////////////////////

    while (window.isOpen())
    {
        auto isWithinWaterRefillArea = [&](int mouseX, int mouseY) -> bool
        {
            // Logic to determine if the click is within the water refill area (top three tiles)
            return mouseX >= 0 && mouseX <= 150 && mouseY >= 0 && mouseY <= 50;
        };

        sf::Event event;
        while (window.pollEvent(event))
        {
            switch (event.type)
            {

            case sf::Event::Closed:
                window.close();
                break;

            case sf::Event::MouseButtonPressed:
                if (isWithinWaterRefillArea(event.mouseButton.x, event.mouseButton.y))
                {
                    wateringCanTextureIndex = 0;
                    wateringCanIcon.setTexture(wateringCanTextures[wateringCanTextureIndex]);
                    wateringCanClicks = 0;
                }
                if (event.mouseButton.button == sf::Mouse::Left)
                {
                    int x = event.mouseButton.x / (tileSize);
                    int y = (event.mouseButton.y - 52) / (tileSize);

                    // Skip if the clicked tile is a border tile
                    if (x == 0 || x == 11 || y == 0 || y == 11)
                    {
                        break;
                    }

                    // Get the tile position where the farmer is standing
                    int personTileX = static_cast<int>(person.getPosition().x) / (tileSize);
                    int personTileY = static_cast<int>(person.getPosition().y - 52) / (tileSize);

                    // Check if the clicked tile is adjacent to or the same as where the person is standing
                    if (abs(x - personTileX) <= 1 && abs(y - personTileY) <= 1 && event.mouseButton.y < 612)
                    {
                        // Only allow clicking the ground to change the texture if the first inventory spot is selected
                        if (selectedInventoryIndex == 0)
                        {
                            tiles[x][y].setTexture(&soilTexture);
                        }

                        if (selectedInventoryIndex == 1) // Watering can is selected
                        {
                            if (tiles[x][y].getTexture() == &soilTexture) // Only highlight if the tile is soil
                            {
                                // Only highlight if the watering can is not empty
                                if (wateringCanTextureIndex != 4)
                                {
                                    highlightedTiles[x][y] = true;

                                    wateringCanClicks++;
                                }
                            }

                            if (wateringCanClicks >= 6)
                            {
                                // Reset the counter
                                wateringCanClicks = 0;
                                // Cycle through textures
                                wateringCanTextureIndex = (wateringCanTextureIndex + 1) % 5;
                                // Update the texture
                                wateringCanIcon.setTexture(wateringCanTextures[wateringCanTextureIndex]);
                            }
                        }
                    }
                }

                break;

            case sf::Event::KeyPressed:
            {
                // Add directional controls using W S A D
                sf::Vector2f pos = person.getPosition();

                switch (event.key.code)
                {
                case sf::Keyboard::W:
                    pos.y -= tileSize;
                    break;
                case sf::Keyboard::S:
                    pos.y += tileSize;
                    break;
                case sf::Keyboard::A:
                    pos.x -= tileSize;
                    break;
                case sf::Keyboard::D:
                    pos.x += tileSize;
                    break;
                default:
                    break;
                }

                float lowerLimitY = 692.0f;
                float upperLimitY = 52.0f;
                float lowerLimitX = 0.0f;
                float upperLimitX = 642.0f;

                // Check if the new position is within the limits
                if (pos.y >= upperLimitY && pos.y <= lowerLimitY - (tileSize) &&
                    pos.x >= lowerLimitX && pos.x <= upperLimitX - (tileSize))
                {
                    person.setPosition(pos);
                }

                if (event.key.code >= sf::Keyboard::Num1 && event.key.code <= sf::Keyboard::Num9)
                {
                    int newSelection = event.key.code - sf::Keyboard::Num1;

                    // Reset the previous selection's border to black if any
                    if (selectedInventoryIndex != -1)
                    {
                        inventory[selectedInventoryIndex].setOutlineColor(sf::Color::Black);
                    }

                    // Update the new selection
                    selectedInventoryIndex = newSelection;

                    // Set the new selection's border to white
                    inventory[selectedInventoryIndex].setOutlineColor(sf::Color::White);
                }
                else if (event.key.code == sf::Keyboard::Num0)
                {
                    // Reset the previous selection's border to black if any
                    if (selectedInventoryIndex != -1)
                    {
                        inventory[selectedInventoryIndex].setOutlineColor(sf::Color::Black);
                    }

                    // Update the new selection to the last slot
                    selectedInventoryIndex = inventorySize - 1;

                    // Set the new selection's border to white
                    inventory[selectedInventoryIndex].setOutlineColor(sf::Color::White);
                }
            }
            break;

            default:
                // Do nothing for other events
                break;
            }
        }

        window.clear(sf::Color::Black);

        //////////////////////////
        // Drawing the graphics //
        //////////////////////////

        for (int i = 0; i < 12; ++i)
        {
            for (int j = 0; j < 12; ++j)
            {
                window.draw(tiles[i][j]);
            }
        }

        for (int i = 0; i < 13; ++i)
        {
            for (int j = 0; j < 2; ++j)
            {
                window.draw(inventoryBackgroundTiles[i][j]);
            }
        }

        for (int i = 0; i < 12; ++i)
        {
            window.draw(waterTiles[i]);
        }

        for (int i = 0; i < 10; ++i)
        {
            window.draw(inventory[i]);
        }

        // Redraw the selected inventory item to bring its border to the top
        if (selectedInventoryIndex != -1)
        {
            window.draw(inventory[selectedInventoryIndex]);
        }

        window.draw(wateringCanIcon);

        window.draw(hoeIcon);

        for (int i = 0; i < 12; ++i)
        {
            for (int j = 0; j < 12; ++j)
            {
                if (highlightedTiles[i][j])
                {
                    blueBorder.setPosition(i * tileSize, j * tileSize + 52);
                    window.draw(blueBorder);
                }
            }
        }

        window.draw(person);

        window.display();
    }

    return 0;
}
