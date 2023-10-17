// main.cpp
#include "Farm.hpp"
#include "Crop.hpp"
#include "SpringCrop.hpp"
#include "SummerCrop.hpp"
#include "AutumnCrop.hpp"
#include "WinterCrop.hpp"
#include "Parsnip.hpp"
#include "Kale.hpp"
#include "Wheat.hpp"
#include "Cabbage.hpp"
#include "Eggplant.hpp"
#include "Yam.hpp"
#include "Rhubarb.hpp"
#include "Beetroot.hpp"
#include "Time.hpp"
#include "ShippingBin.hpp"
#include "Coins.hpp"
#include "Inventory.hpp"

#include <iostream>
#include <string>
#include <filesystem>
#include <fstream>
#include "nlohmann/json.hpp"
#include <vector>

int main(void)
{

    namespace fs = std::filesystem;
    using json = nlohmann::json;

    std::string savesDirectory = "saves";
    std::vector<fs::path> jsonFiles;

    for (const auto &entry : fs::directory_iterator(savesDirectory))
    {
        if (entry.is_regular_file() && entry.path().extension() == ".json")
        {
            jsonFiles.push_back(entry.path());
        }
    }

    if (jsonFiles.empty())
    {
        std::cout << "No JSON files found in the 'saves' directory." << std::endl;
    }

    std::cout << "Available JSON files: " << std::endl;
    for (size_t i = 0; i < jsonFiles.size(); ++i)
    {
        std::cout << i + 1 << ". " << jsonFiles[i].filename() << "\n";
    }
    std::cout << jsonFiles.size() + 1 << ". Don't use a save " << std::endl;

    int choice;
    std::cout << "Select a file (1-" << jsonFiles.size() + 1 << "): ";
    std::cin >> choice;

    if (choice >= 1 && choice <= static_cast<int>(jsonFiles.size()))
    {
        std::string selectedFile = jsonFiles[choice - 1].string();
        std::ifstream fileStream(selectedFile);
        if (fileStream.is_open())
        {
            json jsonData;
            fileStream >> jsonData;
            std::cout << "Selected JSON file: " << selectedFile << "\n";
        }
        else
        {
            std::cerr << "Failed to open the selected JSON file.\n";
        }
    }
    else if (choice == static_cast<int>(jsonFiles.size()) + 1)
    {
        std::cout << "You chose not to use a save.\n";
    }
    else
    {
        std::cout << "Invalid choice. Not using a save.\n";
    }

    // get the dimensions of the farm from the user
    int x_dim = 6;
    int y_dim = 7;
    int x, y;
    // create the farm
    Farm farm(x_dim, y_dim);
    // create a Time object to track the in-game time
    Time time;
    // calculate the maximum number of crops
    int maxCrops = farm.getMaxCrops();
    // create an array to store the crops locally in the main file
    Crop *crops[maxCrops];
    // initialise variables for the below while loop, which contains the content of the game.
    ShippingBin shippingBin;
    Coins coins;
    Inventory inventory;
    int currentCropCount = 0;
    bool gameInProgress = true;
    std::string cropOptions[8] = {"Parsnip", "Kale", "Wheat", "Cabbage", "Eggplant", "Yam", "Rhubarb", "Beetroot"};
    // main while loop which repeats while the user hasn't prompted the game to end
    while (gameInProgress && currentCropCount < maxCrops)
    {
        // check for maturity of crops
        for (int i = 0; i < currentCropCount; i++)
        {
            if (crops[i]->getAge() == crops[i]->getGrowingTime())
            {
                crops[i]->setMature(true);
            }
            if (crops[i]->getAge() - crops[i]->getGrowingTime() >= crops[i]->getDecayTime())
            {
                crops[i]->setDecayed(true);
                Crop ***farmField = farm.getFarmField();
                x = crops[i]->getX();
                y = crops[i]->getY();
                std::cout << "Your " << crops[i]->getName() << " crop at (" << crops[i]->getX() << "," << crops[i]->getY() << ") has decayed." << std::endl;
                farm.removeCrop(farmField[x][y]);
            }
        }
        // take a command to prompt the game what to do.
        std::string command;
        std::cout << "| Purchase | Inventory | Plant | Harvest | Remove | Coins | Info | Map | Skip | Exit |: ";
        std::cin >> command;
        // PURCHASE
        if (command == "Purchase" || command == "purchase" || command == "PURCHASE")
        {
            if (inventory.canAddCrop() == true)
            {
                // Display the list of available crops and their prices
                std::string cropToPurchase;
                std::cout << "| Parsnip | Kale | Wheat | Cabbage | Eggplant | Yam | Rhubarb | Beetroot |: ";
                std::cin >> cropToPurchase;
                // if the user entered "Parsnip"...
                if (cropToPurchase == "Parsnip" || cropToPurchase == "parsnip" || cropToPurchase == "PARSNIP")
                {
                    Parsnip *parsnip = new Parsnip;
                    if (coins.getCoins() >= parsnip->getSeedPrice())
                    {
                        if (inventory.addCrop(parsnip))
                        {
                            coins.removeCoins(parsnip->getSeedPrice());
                            std::cout << "You purchased a Parsnip seed for " << parsnip->getSeedPrice() << " coins." << std::endl;
                        }
                        else
                        {
                            std::cout << "Your inventory is full." << std::endl;
                            delete parsnip;
                        }
                    }
                    else
                    {
                        std::cout << "You don't have enough coins." << std::endl;
                    }
                    // if the user entered "Kale"...
                }
                else if (cropToPurchase == "Kale" || cropToPurchase == "kale" || cropToPurchase == "KALE")
                {
                    Kale *kale = new Kale;
                    if (coins.getCoins() >= kale->getSeedPrice())
                    {
                        if (inventory.addCrop(kale))
                        {
                            coins.removeCoins(kale->getSeedPrice());
                            std::cout << "You purchased a Kale seed for " << kale->getSeedPrice() << " coins." << std::endl;
                        }
                        else
                        {
                            std::cout << "Your inventory is full." << std::endl;
                            delete kale;
                        }
                    }
                    else
                    {
                        std::cout << "You don't have enough coins." << std::endl;
                    }
                    // if the user entered "Wheat"...
                }
                else if (cropToPurchase == "Wheat" || cropToPurchase == "wheat" || cropToPurchase == "WHEAT")
                {
                    Wheat *wheat = new Wheat;
                    if (coins.getCoins() >= wheat->getSeedPrice())
                    {
                        if (inventory.addCrop(wheat))
                        {
                            coins.removeCoins(wheat->getSeedPrice());
                            std::cout << "You purchased a Wheat seed for " << wheat->getSeedPrice() << " coins." << std::endl;
                        }
                        else
                        {
                            std::cout << "Your inventory is full." << std::endl;
                            delete wheat;
                        }
                    }
                    else
                    {
                        std::cout << "You don't have enough coins." << std::endl;
                    }
                    // if the user entered "Cabbage"...
                }
                else if (cropToPurchase == "Cabbage" || cropToPurchase == "cabbage" || cropToPurchase == "CABBAGE")
                {
                    Cabbage *cabbage = new Cabbage;
                    if (coins.getCoins() >= cabbage->getSeedPrice())
                    {
                        if (inventory.addCrop(cabbage))
                        {
                            coins.removeCoins(cabbage->getSeedPrice());
                            std::cout << "You purchased a Cabbage seed for " << cabbage->getSeedPrice() << " coins." << std::endl;
                        }
                        else
                        {
                            std::cout << "Your inventory is full." << std::endl;
                            delete cabbage;
                        }
                    }
                    else
                    {
                        std::cout << "You don't have enough coins." << std::endl;
                    }
                    // if the user entered "Eggplant"...
                }
                else if (cropToPurchase == "Eggplant" || cropToPurchase == "eggplant" || cropToPurchase == "EGGPLANT")
                {
                    Eggplant *eggplant = new Eggplant;
                    if (coins.getCoins() >= eggplant->getSeedPrice())
                    {
                        if (inventory.addCrop(eggplant))
                        {
                            coins.removeCoins(eggplant->getSeedPrice());
                            std::cout << "You purchased an Eggplant seed for " << eggplant->getSeedPrice() << " coins." << std::endl;
                        }
                        else
                        {
                            std::cout << "Your inventory is full." << std::endl;
                            delete eggplant;
                        }
                    }
                    else
                    {
                        std::cout << "You don't have enough coins." << std::endl;
                    }
                    // if the user entered "Yam"...
                }
                else if (cropToPurchase == "Yam" || cropToPurchase == "yam" || cropToPurchase == "YAM")
                {
                    Yam *yam = new Yam;
                    if (coins.getCoins() >= yam->getSeedPrice())
                    {
                        if (inventory.addCrop(yam))
                        {
                            coins.removeCoins(yam->getSeedPrice());
                            std::cout << "You purchased a Yam seed for " << yam->getSeedPrice() << " coins." << std::endl;
                        }
                        else
                        {
                            std::cout << "Your inventory is full." << std::endl;
                            delete yam;
                        }
                    }
                    else
                    {
                        std::cout << "You don't have enough coins." << std::endl;
                    }
                    // if the user entered "Rhubarb"...
                }
                else if (cropToPurchase == "Rhubarb" || cropToPurchase == "rhubarb" || cropToPurchase == "RHUBARB")
                {
                    Rhubarb *rhubarb = new Rhubarb;
                    if (coins.getCoins() >= rhubarb->getSeedPrice())
                    {
                        if (inventory.addCrop(rhubarb))
                        {
                            coins.removeCoins(rhubarb->getSeedPrice());
                            std::cout << "You purchased a Rhubarb seed for " << rhubarb->getSeedPrice() << " coins." << std::endl;
                        }
                        else
                        {
                            std::cout << "Your inventory is full." << std::endl;
                            delete rhubarb;
                        }
                    }
                    else
                    {
                        std::cout << "You don't have enough coins." << std::endl;
                    }
                    // if the user entered "Beetroot"...
                }
                else if (cropToPurchase == "Beetroot" || cropToPurchase == "beetroot" || cropToPurchase == "BEETROOT")
                {
                    Beetroot *beetroot = new Beetroot;
                    if (coins.getCoins() >= beetroot->getSeedPrice())
                    {
                        if (inventory.addCrop(beetroot))
                        {
                            coins.removeCoins(beetroot->getSeedPrice());
                            std::cout << "You purchased a Beetroot seed for " << beetroot->getSeedPrice() << " coins." << std::endl;
                        }
                        else
                        {
                            std::cout << "Your inventory is full." << std::endl;
                            delete beetroot;
                        }
                    }
                    else
                    {
                        std::cout << "You don't have enough coins." << std::endl;
                    }
                }
                else
                {
                    std::cout << "Invalid crop." << std::endl;
                }
            }
            else
            {
                std::cout << "Your inventory is full" << std::endl;
            }
            // INVENTORY
        }
        else if (command == "Inventory" || command == "inventory" || command == "INVENTORY")
        {
            inventory.displayInventory();
            // PLANT
        }
        else if (command == "Plant" || command == "plant" || command == "PLANT")
        {
            std::string cropToPlant;
            std::cout << "Enter the crop you would like to plant: ";
            std::cin >> cropToPlant;
            // if the user entered "Parsnip"...
            if (cropToPlant == "Parsnip" || cropToPlant == "parsnip" || cropToPlant == "PARSNIP")
            {
                Crop *cropInInventory = inventory.findCrop("Parsnip");
                if (cropInInventory != nullptr)
                {
                    int x, y;
                    std::cout << "Enter the x-coordinate for planting: ";
                    std::cin >> x;
                    std::cout << "Enter the y-coordinate for planting: ";
                    std::cin >> y;
                    int index = inventory.findCropIndex("Parsnip");
                    if (farm.addCrop(cropInInventory, x, y))
                    {
                        crops[currentCropCount] = cropInInventory;
                        currentCropCount++;
                        inventory.removeCrop(cropInInventory, index);
                    }
                    else
                    {
                        std::cout << "Failed to plant your parsnip. Check if the coordinates are valid." << std::endl;
                        cropInInventory = nullptr;
                    }
                }
                else
                {
                    std::cout << "No parsnips exist in your inventory." << std::endl;
                }
                // if the user entered "Kale"...
            }
            else if (cropToPlant == "Kale" || cropToPlant == "kale" || cropToPlant == "KALE")
            {
                Crop *cropInInventory = inventory.findCrop("Kale");
                if (cropInInventory != nullptr)
                {
                    int x, y;
                    std::cout << "Enter the x-coordinate for planting: ";
                    std::cin >> x;
                    std::cout << "Enter the y-coordinate for planting: ";
                    std::cin >> y;
                    int index = inventory.findCropIndex("Kale");
                    if (farm.addCrop(cropInInventory, x, y))
                    {
                        crops[currentCropCount] = cropInInventory;
                        currentCropCount++;
                        inventory.removeCrop(cropInInventory, index);
                    }
                    else
                    {
                        std::cout << "Failed to plant your kale. Check if the coordinates are valid." << std::endl;
                        cropInInventory = nullptr;
                    }
                }
                else
                {
                    std::cout << "No kale exists in your inventory." << std::endl;
                }
                // if the user entered "Wheat"...
            }
            else if (cropToPlant == " Wheat" || cropToPlant == "wheat" || cropToPlant == "WHEAT")
            {
                Crop *cropInInventory = inventory.findCrop("Wheat");
                if (cropInInventory != nullptr)
                {
                    int x, y;
                    std::cout << "Enter the x-coordinate for planting: ";
                    std::cin >> x;
                    std::cout << "Enter the y-coordinate for planting: ";
                    std::cin >> y;
                    int index = inventory.findCropIndex("Wheat");
                    if (farm.addCrop(cropInInventory, x, y))
                    {
                        crops[currentCropCount] = cropInInventory;
                        currentCropCount++;
                        inventory.removeCrop(cropInInventory, index);
                    }
                    else
                    {
                        std::cout << "Failed to plant your wheat. Check if the coordinates are valid." << std::endl;
                        cropInInventory = nullptr;
                    }
                }
                else
                {
                    std::cout << "No wheat exists in your inventory." << std::endl;
                }
                // if the user entered "Cabbage"...
            }
            else if (cropToPlant == " Cabbage" || cropToPlant == "cabbage" || cropToPlant == "CABBAGE")
            {
                Crop *cropInInventory = inventory.findCrop("Cabbage");
                if (cropInInventory != nullptr)
                {
                    int x, y;
                    std::cout << "Enter the x-coordinate for planting: ";
                    std::cin >> x;
                    std::cout << "Enter the y-coordinate for planting: ";
                    std::cin >> y;
                    int index = inventory.findCropIndex("Cabbage");
                    if (farm.addCrop(cropInInventory, x, y))
                    {
                        crops[currentCropCount] = cropInInventory;
                        currentCropCount++;
                        inventory.removeCrop(cropInInventory, index);
                    }
                    else
                    {
                        std::cout << "Failed to plant your cabbage. Check if the coordinates are valid." << std::endl;
                        cropInInventory = nullptr;
                    }
                }
                else
                {
                    std::cout << "No cabbage exists in your inventory." << std::endl;
                }
                // if the user entered "Eggplant"...
            }
            else if (cropToPlant == "Eggplant" || cropToPlant == "eggplant" || cropToPlant == "EGGPLANT")
            {
                Crop *cropInInventory = inventory.findCrop("Eggplant");
                if (cropInInventory != nullptr)
                {
                    int x, y;
                    std::cout << "Enter the x-coordinate for planting: ";
                    std::cin >> x;
                    std::cout << "Enter the y-coordinate for planting: ";
                    std::cin >> y;
                    int index = inventory.findCropIndex("Eggplant");
                    if (farm.addCrop(cropInInventory, x, y))
                    {
                        crops[currentCropCount] = cropInInventory;
                        currentCropCount++;
                        inventory.removeCrop(cropInInventory, index);
                    }
                    else
                    {
                        std::cout << "Failed to plant your eggplant. Check if the coordinates are valid." << std::endl;
                        cropInInventory = nullptr;
                    }
                }
                else
                {
                    std::cout << "No eggplants exist in your inventory." << std::endl;
                }
                // if the user entered "Yam"...
            }
            else if (cropToPlant == "Yam" || cropToPlant == "yam" || cropToPlant == "YAM")
            {
                Crop *cropInInventory = inventory.findCrop("Yam");
                if (cropInInventory != nullptr)
                {
                    int x, y;
                    std::cout << "Enter the x-coordinate for planting: ";
                    std::cin >> x;
                    std::cout << "Enter the y-coordinate for planting: ";
                    std::cin >> y;
                    int index = inventory.findCropIndex("Yam");
                    if (farm.addCrop(cropInInventory, x, y))
                    {
                        crops[currentCropCount] = cropInInventory;
                        currentCropCount++;
                        inventory.removeCrop(cropInInventory, index);
                    }
                    else
                    {
                        std::cout << "Failed to plant your yam. Check if the coordinates are valid." << std::endl;
                        cropInInventory = nullptr;
                    }
                }
                else
                {
                    std::cout << "No yams exist in your inventory." << std::endl;
                }
                // if the user entered "Rhubarb"...
            }
            else if (cropToPlant == "Rhubarb" || cropToPlant == "rhubarb" || cropToPlant == "RHUBARB")
            {
                Crop *cropInInventory = inventory.findCrop("Rhubarb");
                if (cropInInventory != nullptr)
                {
                    int x, y;
                    std::cout << "Enter the x-coordinate for planting: ";
                    std::cin >> x;
                    std::cout << "Enter the y-coordinate for planting: ";
                    std::cin >> y;
                    int index = inventory.findCropIndex("Rhubarb");
                    if (farm.addCrop(cropInInventory, x, y))
                    {
                        crops[currentCropCount] = cropInInventory;
                        currentCropCount++;
                        inventory.removeCrop(cropInInventory, index);
                    }
                    else
                    {
                        std::cout << "Failed to plant your rhubarb. Check if the coordinates are valid." << std::endl;
                        cropInInventory = nullptr;
                    }
                }
                else
                {
                    std::cout << "No rhubarbs exist in your inventory." << std::endl;
                }
                // if the user entered "Beetroot"...
            }
            else if (cropToPlant == "Beetroot" || cropToPlant == "beetroot" || cropToPlant == "BEETROOT")
            {
                Crop *cropInInventory = inventory.findCrop("Beetroot");
                if (cropInInventory != nullptr)
                {
                    int x, y;
                    std::cout << "Enter the x-coordinate for planting: ";
                    std::cin >> x;
                    std::cout << "Enter the y-coordinate for planting: ";
                    std::cin >> y;
                    int index = inventory.findCropIndex("Beetroot");
                    if (farm.addCrop(cropInInventory, x, y))
                    {
                        crops[currentCropCount] = cropInInventory;
                        currentCropCount++;
                        inventory.removeCrop(cropInInventory, index);
                    }
                    else
                    {
                        std::cout << "Failed to plant your beetroot. Check if the coordinates are valid." << std::endl;
                        cropInInventory = nullptr;
                    }
                }
                else
                {
                    std::cout << "No beetroots exist in your inventory." << std::endl;
                }
            }
            else
            {
                std::cout << "Invalid crop." << std::endl;
            }
            // HARVEST
        }
        else if (command == "Harvest" || command == "harvest" || command == "HARVEST")
        {
            std::cout << "Enter the x-coordinate of the crop: ";
            std::cin >> x;
            std::cout << "Enter the y-coordinate of this crop: ";
            std::cin >> y;
            Crop ***farmField = farm.getFarmField();
            if (farmField[x][y] != nullptr && farmField[x][y]->isMature() == true)
            {
                Crop *cropToHarvest = farmField[x][y];
                shippingBin.increaseSize();
                Crop **harvestedCrops = shippingBin.getHarvestedCrops();
                farm.harvestCrop(cropToHarvest, harvestedCrops);
                std::cout << "The " << cropToHarvest->getName() << " has been harvested." << std::endl;
            }
            else if (farmField[x][y] != nullptr && farmField[x][y]->isMature() == false)
            {
                std::cout << "The crop is not mature." << std::endl;
            }
            else
            {
                std::cout << "Invalid coordinates." << std::endl;
            }
            // REMOVE
        }
        else if (command == "Remove" || command == "remove" || command == "REMOVE")
        {
            std::cout << "Enter the x-coordinate of the crop: ";
            std::cin >> x;
            std::cout << "Enter the y-coordinate of the crop: ";
            std::cin >> y;
            Crop ***farmField = farm.getFarmField();
            if (farmField[x][y] != nullptr)
            {
                Crop *cropToRemove = farmField[x][y];
                farm.removeCrop(cropToRemove);
                std::cout << "The crop has been removed." << std::endl;
            }
            else
            {
                std::cout << "Invalid coordinates." << std::endl;
            }
            // COINS
        }
        else if (command == "Coins" || command == "coins" || command == "COINS")
        {
            std::cout << "Current balance: " << coins.getCoins() << " coins" << std::endl;
            // INFO
        }
        else if (command == "Info" || command == "info" || command == "INFO")
        {
            farm.getAllCropsInfo();
            // MAP
        }
        else if (command == "Map" || command == "map" || command == "MAP")
        {
            farm.visualizeFarmField();
            // SKIP
        }
        else if (command == "Skip" || command == "skip" || command == "SKIP")
        {
            time.incrementDay(&farm);
            std::cout << "Day " << time.getDay() << ", Month " << time.getMonth() << ", Year " << time.getYear() << std::endl;
            Crop **harvestedCrops = shippingBin.getHarvestedCrops();
            for (int i = 0; i < shippingBin.getSize(); i++)
            {
                coins.addCoins(harvestedCrops[i]->getSellPrice());
            }
            shippingBin.reset();
            // EXIT
        }
        else if (command == "Exit" || command == "exit" || command == "EXIT")
        {
            gameInProgress = false;
            std::cout << "Game over. Thank you for playing." << std::endl;

            json gameState;

            gameState["Coins"] = coins.getCoins();
            gameState["Time"] = time.getDaysPassed();

            // Exporting farm field
            std::vector<Crop***> serializedFarm;
            serializedFarm.push_back(farm.getFarmField());

            // Serialize the game state
            std::string serializedData = gameState.dump();

            // Save the serialized data to a file
            std::ofstream outputFile("saves/game_state.json");
            outputFile << serializedData;
            outputFile.close();
        }
        else
        {
            std::cout << "Invalid command." << std::endl;
        }
    }
    return 0;
}
