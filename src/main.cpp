#include <SFML/Graphics.hpp>
#include <iostream>
#include "include/Person.h"
#include "include/Farm.h"
#include "include/Inventory.h"
#include "include/Weather.h"
#include "include/Time.h"
#include "include/Parsnip.h"
#include "include/PinkTurnip.h"
#include "include/RedTurnip.h"
#include "include/Carrot.h"
#include "include/GreenTurnip.h"
#include "include/WinterRoot.h"
#include "include/Beetroot.h"
#include "include/Turnip.h"
#include "include/CropsToSell.h"
#include "include/Money.h"

#include <vector>
#include <list>
#include <map>
#include <functional>
#include <memory>

int main()
{
    /////////////////////////////
    // Initialise the textures //
    /////////////////////////////

    // Create the window

    Farm myFarm;
    Inventory myInventory;
    Weather myWeather;
    Time myTime;
    CropsToSell myCropsToSell;
    Money myMoney(500);
    sf::RenderWindow window(sf::VideoMode(600, 755), "My Farm");

    std::string currentSeason = myTime.getCurrentSeason();

    // Load textures
    std::vector<std::string> weatherFiles = {
        "src/assets/sunny.png",
        "src/assets/rainy.png",
    };

    if (!myWeather.loadTextures(weatherFiles))
    {
        return -1;
    }

    myWeather.setPosition(550, 0);

    myWeather.setCurrentWeather(0);

    std::list<std::unique_ptr<Crop>> cropList;
    std::map<int, std::function<std::unique_ptr<Crop>()>> cropFactoryMap = {
        {2, []()
         { return std::make_unique<Parsnip>(); }},
        {3, []()
         { return std::make_unique<Turnip>(); }},
        {4, []()
         { return std::make_unique<PinkTurnip>(); }},
        {5, []()
         { return std::make_unique<RedTurnip>(); }},
        {6, []()
         { return std::make_unique<Carrot>(); }},
        {7, []()
         { return std::make_unique<GreenTurnip>(); }},
        {8, []()
         { return std::make_unique<WinterRoot>(); }},
        {9, []()
         { return std::make_unique<Beetroot>(); }},
    };

    sf::Texture pathTexture;
    if (!pathTexture.loadFromFile("src/assets/path.jpeg"))
    {
        return -1;
    }

    sf::Font font;
    if (!font.loadFromFile("src/assets/font.ttf"))
    {
        return -1;
    }

    sf::Text timeText;
    timeText.setFont(font);
    timeText.setCharacterSize(18);
    timeText.setFillColor(sf::Color::White);
    timeText.setPosition(476, 5);

    sf::Text seasonText;
    seasonText.setFont(font);
    seasonText.setCharacterSize(12);
    seasonText.setFillColor(sf::Color::White);
    seasonText.setPosition(476, 26);

    sf::Text moneyText;
    moneyText.setFont(font);
    moneyText.setCharacterSize(24);
    moneyText.setFillColor(sf::Color::Black);
    moneyText.setOutlineThickness(2);            // set the thickness of the outline
    moneyText.setOutlineColor(sf::Color::White); // set the color of the outline
    moneyText.setPosition(355, 10);

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

    sf::Texture bedTexture;
    if (!bedTexture.loadFromFile("src/assets/bed.png"))
    {
        return -1;
    }

    sf::Texture shopTexture;
    if (!shopTexture.loadFromFile("src/assets/shop.png"))
    {
        return -1;
    }

    sf::Texture moneyTexture;
    if (!moneyTexture.loadFromFile("src/assets/money.jpeg"))
    {
        return -1;
    }

    sf::Texture lTimeTexture;
    if (!lTimeTexture.loadFromFile("src/assets/time-left.png"))
    {
        return -1;
    }

    sf::Texture rTimeTexture;
    if (!rTimeTexture.loadFromFile("src/assets/time-right.png"))
    {
        return -1;
    }

    sf::Texture hoeIconTexture;
    if (!hoeIconTexture.loadFromFile("src/assets/hoe.png"))
    {
        return -1;
    }

    std::vector<std::string> cropNames = {"parsnip", "turnip", "pink_turnip", "red_turnip", "carrot", "green_turnip", "winter_root", "beetroot"};
    std::vector<sf::Texture> cropTextures;
    std::vector<sf::Sprite> cropIcons;

    int positionX = 147;
    int positionY = 677;
    int slotDistance = 52; // Distance between slots, if they are different distances apart adjust as needed.

    // Preallocate space to avoid reallocation
    cropTextures.reserve(cropNames.size());

    for (const auto &cropName : cropNames)
    {
        sf::Texture texture;
        if (!texture.loadFromFile("src/assets/" + cropName + "1.png"))
        {
            std::cout << "Failed to load texture for: " << cropName << std::endl;
            return -1;
        }
        else
        {
            std::cout << "Successfully loaded texture for: " << cropName << std::endl;
        }

        // Store the texture in a vector
        cropTextures.push_back(texture);

        // Create a sprite from the last texture in the vector
        sf::Sprite icon(cropTextures.back());

        sf::Vector2u textureSize = texture.getSize();
        float scaleX = static_cast<float>(50) / static_cast<float>(textureSize.x);
        float scaleY = static_cast<float>(50) / static_cast<float>(textureSize.y);
        icon.setScale(scaleX, scaleY);

        icon.setPosition(positionX, positionY);
        positionX += slotDistance; // Increment position for the next icon.

        cropIcons.push_back(icon); // Store the icon in the vector.
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

    sf::RectangleShape waterTiles[12];
    sf::RectangleShape bedTile;
    sf::RectangleShape shopTile;

    shopTile.setSize(sf::Vector2f(50, 50));
    shopTile.setTexture(&shopTexture);
    bedTile.setSize(sf::Vector2f(50, 50));
    bedTile.setTexture(&bedTexture);

    for (int i = 0; i < 12; ++i)
    {
        waterTiles[i].setSize(sf::Vector2f(50, 50));
        waterTiles[i].setPosition(i * 50, 0);

        if (i == 0 || i == 1 || i == 2)
        {
            waterTiles[i].setTexture(&waterTexture);
        }
        else if (i == 3 || i == 4 || i == 5)
        {
            waterTiles[i].setTexture(&houseTexture);
            if (i == 4)
            {
                bedTile.setPosition(i * 50, 0);
            }
        }
        else if (i == 6)
        {
            waterTiles[i].setTexture(&houseTexture);
            shopTile.setPosition(i * 50, 0);
        }
        else if (i == 7 || i == 8)
        {
            waterTiles[i].setTexture(&moneyTexture);
        }
        else if (i == 9)
        {
            waterTiles[i].setTexture(&lTimeTexture);
        }
        else if (i == 10)
        {
            waterTiles[i].setTexture(&rTimeTexture);
        }
        else
        {
            waterTiles[i].setTexture(&pathTexture);
        }
    }

    // Define tile size
    int tileSize = 50;

    Person person("src/assets/person.png", tileSize);
    person.setPosition(52 + 1, 52 + 1);

    /////////////////////////////
    // Logic for button inputs //
    /////////////////////////////

    while (window.isOpen())
    {
        timeText.setString("Day: " + std::to_string(myTime.getCurrentDay()));
        seasonText.setString(myTime.getCurrentSeason());
        moneyText.setString("$" + std::to_string(myMoney.getAmount()));
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
            {

                if (event.mouseButton.button == sf::Mouse::Left)
                {
                    sf::Vector2f pos = person.getPosition();
                    int personTileX = static_cast<int>(pos.x) / tileSize;
                    int personTileY = static_cast<int>(pos.y - 52) / tileSize;

                    sf::Vector2i clickedTile = myFarm.getClickedTile(event.mouseButton.x, event.mouseButton.y);
                    int x = clickedTile.x;
                    int y = clickedTile.y;

                    int clickedInventoryIndex = -1; // Initialize to an invalid value

                    // Loop over each inventory index from 2 to 9
                    for (int i = 2; i <= 9; ++i)
                    {
                        int lowerX = 145 + (i - 2) * 52;
                        int upperX = lowerX + 52;
                        int lowerY = 680;
                        int upperY = 730;

                        // Check if the mouse is clicked within the bounds
                        if (event.mouseButton.x > lowerX && event.mouseButton.x < upperX && event.mouseButton.y > lowerY && event.mouseButton.y < upperY)
                        {
                            clickedInventoryIndex = i;
                            break;
                        }
                    }

                    if (clickedInventoryIndex >= 2 && clickedInventoryIndex <= 9)
                    {
                        if (myInventory.getCropCount(clickedInventoryIndex) < 99)
                        {
                            if (myMoney.getAmount() >= myInventory.getCropBuyPrice(clickedInventoryIndex))
                            {
                                myMoney.addAmount(-myInventory.getCropBuyPrice(clickedInventoryIndex));
                                myInventory.incrementCropCount(clickedInventoryIndex);
                            }
                        }
                    }

                    // Check if the clicked tile is adjacent to or the same as where the person is standing
                    if (abs(x - personTileX) <= 1 && abs(y - personTileY) <= 1)
                    {
                        // Loop through crops to find if any are mature and can be harvested.
                        for (auto it = cropList.begin(); it != cropList.end();)
                        {
                            if ((*it)->getPosition() == sf::Vector2f(x * tileSize, y * tileSize + 52) && (*it)->isMature())
                            {
                                myCropsToSell.addCrop(it->get()); // assuming addCrop takes a Crop pointer
                                myMoney.addAmount((*it)->getSellValue());
                                it = cropList.erase(it);

                                // Reset the tile's texture to normal soil
                                myFarm.setTileTexture(x, y, myFarm.getSoilTexture());
                            }
                            else
                            {
                                ++it;
                            }
                        }

                        if (isWithinWaterRefillArea(event.mouseButton.x, event.mouseButton.y))
                        {
                            wateringCanTextureIndex = 0;
                            wateringCanIcon.setTexture(wateringCanTextures[wateringCanTextureIndex]);
                            wateringCanClicks = 0;
                        }
                        if (event.mouseButton.x > 200 && event.mouseButton.x < 250 && event.mouseButton.y < 60)
                        {
                            myTime.passDay();
                            myWeather.updateWeather();

                            if (myWeather.getCurrentWeather() == Weather::RAINY)
                            {
                                std::cout << "Weather is RAINY." << std::endl;
                                for (int x = 0; x < 12; ++x)
                                {
                                    for (int y = 0; y < 12; ++y)
                                    {
                                        if (myFarm.getTileTexture(x, y) == myFarm.getSoilTexture())
                                        {
                                            std::cout << "Changing soil to wet at position (" << x << ", " << y << ")." << std::endl;
                                            myFarm.setTileTexture(x, y, myFarm.getWetSoilTexture());
                                        }
                                    }
                                }
                            }

                            // Step 2: Water and grow the crops
                            for (int x = 0; x < 12; ++x)
                            {
                                for (int y = 0; y < 12; ++y)
                                {
                                    if (myFarm.getTileTexture(x, y) == myFarm.getWetSoilTexture())
                                    {
                                        for (auto &crop : cropList)
                                        {
                                            if (crop->getPosition() == sf::Vector2f(x * tileSize, y * tileSize + 52))
                                            {
                                                crop->water();
                                                crop->grow(currentSeason);
                                            }
                                        }
                                    }
                                }
                            }
                            if (myWeather.getCurrentWeather() != Weather::RAINY)
                            {
                                std::cout << "Current Day: " << myTime.getCurrentDay() << std::endl;
                                for (int x = 0; x < 12; ++x)
                                {
                                    for (int y = 0; y < 12; ++y)
                                    {
                                        if (myFarm.getTileTexture(x, y) == myFarm.getWetSoilTexture())
                                        {
                                            myFarm.setTileTexture(x, y, myFarm.getSoilTexture());
                                        }
                                    }
                                }
                            }
                            for (auto &crop : cropList)
                            {
                                crop->grow(currentSeason);
                            }
                        }
                        if (event.mouseButton.y > 60 && event.mouseButton.y < 640)
                        {
                            if (myInventory.getSelectedInventoryIndex() == 0 && myFarm.getTileTexture(x, y) != myFarm.getWetSoilTexture())
                            {
                                myFarm.setTileTexture(x, y, myFarm.getSoilTexture());
                            }

                            if (myInventory.getSelectedInventoryIndex() == 1 && wateringCanTextureIndex != 4)
                            {
                                if (myFarm.getTileTexture(x, y) == myFarm.getSoilTexture())
                                {
                                    myFarm.setTileTexture(x, y, myFarm.getWetSoilTexture());
                                    wateringCanClicks++;
                                    // Find the crops at this location and water it
                                    for (auto &crop : cropList)
                                    {
                                        if (crop->getPosition() == sf::Vector2f(x * tileSize, y * tileSize + 52))
                                        {
                                            crop->water();
                                        }
                                    }
                                    if (wateringCanClicks >= 10)
                                    {
                                        wateringCanClicks = 0;
                                        wateringCanTextureIndex = (wateringCanTextureIndex + 1) % 5;
                                        wateringCanIcon.setTexture(wateringCanTextures[wateringCanTextureIndex]);
                                    }
                                }
                            }
                            int selectedInventoryIndex = myInventory.getSelectedInventoryIndex();
                            if (cropFactoryMap.find(selectedInventoryIndex) != cropFactoryMap.end())
                            {
                                bool isTileWet = (myFarm.getTileTexture(x, y) == myFarm.getWetSoilTexture());
                                if (myFarm.getTileTexture(x, y) == myFarm.getSoilTexture() ||
                                    myFarm.getTileTexture(x, y) == myFarm.getWetSoilTexture())
                                {
                                    // Check if there's enough of this crop in the inventory
                                    if (myInventory.getCropCount(selectedInventoryIndex) > 0)
                                    {
                                        std::unique_ptr<Crop> newCrop = cropFactoryMap[selectedInventoryIndex]();
                                        newCrop->plant(x * tileSize, y * tileSize + 52, isTileWet);
                                        cropList.push_back(std::move(newCrop));

                                        // Decrease the crop count in the inventory
                                        myInventory.decrementCropCount(selectedInventoryIndex);
                                    }
                                }
                            }
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
                    person.setPosition(pos.x, pos.y);
                }

                if (event.key.code >= sf::Keyboard::Num1 && event.key.code <= sf::Keyboard::Num9)
                {
                    int newSelection = event.key.code - sf::Keyboard::Num1;
                    myInventory.setSelection(newSelection);
                }
                else if (event.key.code == sf::Keyboard::Num0)
                {
                    myInventory.setSelection(9);
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

        myFarm.draw(window);

        myInventory.draw(window);

        for (int i = 0; i < 12; ++i)
        {
            window.draw(waterTiles[i]);
        }

        window.draw(myWeather.getSprite());

        window.draw(wateringCanIcon);

        window.draw(timeText);

        window.draw(seasonText);

        window.draw(moneyText);

        window.draw(hoeIcon);

        window.draw(bedTile);

        window.draw(shopTile);

        for (auto &crop : cropList)
        {
            crop->draw(window);
        }

        for (const auto &icon : cropIcons)
        {
            if (icon.getTexture() == nullptr)
            {
                std::cout << "Icon has no texture!" << std::endl;
            }
            window.draw(icon);
        }

        window.draw(person.getSprite());

        window.display();
    }

    return 0;
}
