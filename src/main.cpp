#include <SFML/Graphics.hpp>

int main()
{
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

    sf::Texture inventoryBackgroundTexture;
    if (!inventoryBackgroundTexture.loadFromFile("src/assets/inventory-background.jpeg"))
    {
        return -1;
    }

    int inventoryBackgroundStartY = 657;
    int inventoryBackgroundTileSize = 50;

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

    while (window.isOpen())
    {
        sf::Event event;
        while (window.pollEvent(event))
        {
            switch (event.type)
            {

            case sf::Event::Closed:
                window.close();
                break;

            case sf::Event::MouseButtonPressed:
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
                        tiles[x][y].setTexture(&soilTexture); // Set texture to soil
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
            }
            break;

            default:
                // Do nothing for other events
                break;
            }
        }

        window.clear(sf::Color::Black);

        // Draw a 12x12 grid of textured squares
        for (int i = 0; i < 12; ++i)
        {
            for (int j = 0; j < 12; ++j)
            {
                window.draw(tiles[i][j]);
            }
        }

        // Draw the inventory background tiles
        for (int i = 0; i < 13; ++i)
        {
            for (int j = 0; j < 2; ++j)
            {
                window.draw(inventoryBackgroundTiles[i][j]);
            }
        }

        // Draw the inventory bar
        for (int i = 0; i < 10; ++i)
        {
            window.draw(inventory[i]);
        }

        window.draw(person);

        window.display();
    }

    return 0;
}
