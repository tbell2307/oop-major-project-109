#include "Farm.hpp"
#include "Crop.hpp"
#include "Parsnip.hpp"
#include "Kale.hpp"
#include "Radish.hpp"
#include "Wheat.hpp"
#include "Eggplant.hpp"
#include "Beetroot.hpp"

#include <iostream>

int main(void) {
    //get the name of the farm from the user
    std::string name;
    std::cout << "Enter a name for your farm: ";
    std::getline(std::cin, name);
    //get the location of the farm from the user
    std::string location;
    std::cout << "Where will your farm be located?: ";
    std::getline(std::cin, location);
    //get the x and  y dimensions of the farm from user
    int x, y;
    std::cout << "How big would you like your farm to be? Enter the X dimsensions: ";
    std::cin >> x;
    std::cout << "Enter the Y dimensions: ";
    std::cin >> y;
    //create the farm
    Farm farm(name, location, x, y); // Set the dimensions of the farm field
    //calculate the maximum number of crops
    int maxCrops = farm.getMaxCrops(); 
    //create an array to store the crops
    Crop* crops[maxCrops]; 
    //print basic farm information 
    std::cout << "The dimensions of " << farm.getName() << " farm located in " << farm.getLocation() << " are X: " << farm.getXDim() << " units and Y: " << farm.getYDim() << " units." << std::endl;
    int currentCropCount = 0; 
    bool continuePlanting = true;
    //print the crop varieties
    std::string cropOptions[6] = {"Parsnip", "Kale", "Radish", "Wheat", "Eggplant", "Beetroot"};
    //get crop inputs from the user, adding these to both the array in the main file (crops) as well as the array in the Farm class.
    while (continuePlanting && currentCropCount < maxCrops) {
        std::cout << "The available crop options are..." << std::endl;
        for (int i = 0; i < sizeof(cropOptions) / sizeof(std::string); i++) {
            std::cout << cropOptions[i];
            if (i != ((sizeof(cropOptions) / sizeof(std::string) - 1))) {
                std::cout << " | ";
            }
        }
        std::string cropToPlant;
        std::cout << std::endl << "Enter the crop you would like to plant in " << farm.getName() << " Farm: ";
        std::cin >> cropToPlant;
        //if the user entered "Parsnip"...
        if (cropToPlant == cropOptions[0]) {
            Parsnip* parsnip = new Parsnip("Parsnip", "Spring", 4);
            int x, y;
            std::cout << "Enter the x-coordinate for planting: ";
            std::cin >> x;
            std::cout << "Enter the y-coordinate for planting: ";
            std::cin >> y;

            if (farm.addCrop(parsnip, x, y)) {
                crops[currentCropCount] = parsnip;
                currentCropCount++;
            } else {
                std::cout << "Failed to plant the parsnip. Check if the coordinates are valid." << std::endl;
                delete parsnip;
            }
        //if the user entered "Kale"...
        } else if (cropToPlant == cropOptions[1]) {
            Kale* kale = new Kale("Kale", "Spring", 6);
            int x, y;
            std::cout << "Enter the x-coordinate for planting: ";
            std::cin >> x;
            std::cout << "Enter the y-coordinate for planting: ";
            std::cin >> y;
            if (farm.addCrop(kale, x, y)) {
                crops[currentCropCount] = kale;
                currentCropCount++;
            } else {
                std::cout << "Failed to plant the kale. Check if the coordinates are valid." << std::endl;
                delete kale;
            }
        //if the user entered "Radish"...
        } else if (cropToPlant == cropOptions[2]) {
            Radish* radish = new Radish("Radish", "Summer", 6);
            int x, y;
            std::cout << "Enter the x-coordinate for planting: ";
            std::cin >> x;
            std::cout << "Enter the y-coordinate for planting: ";
            std::cin >> y;
            if (farm.addCrop(radish, x, y)) {
                crops[currentCropCount] = radish;
                currentCropCount++;
            } else {
                std::cout << "Failed to plant the radish. Check if the coordinates are valid." << std::endl;
                delete radish;
            }
        //if the user entered "Wheat"...
        } else if (cropToPlant == cropOptions[3]) {
            Wheat* wheat = new Wheat("Wheat", "Summer", 4);
            int x, y;
            std::cout << "Enter the x-coordinate for planting: ";
            std::cin >> x;
            std::cout << "Enter the y-coordinate for planting: ";
            std::cin >> y;
            if (farm.addCrop(wheat, x, y)) {
                crops[currentCropCount] = wheat;
                currentCropCount++;
            } else {
                std::cout << "Failed to plant the wheat. Check if the coordinates are valid." << std::endl;
                delete wheat;
            }
        //if the user entered "Eggplant"...
        } else if (cropToPlant == cropOptions[4]) {
            Eggplant* eggplant = new Eggplant("Eggplant", "Autumn", 5);
            int x, y;
            std::cout << "Enter the x-coordinate for planting: ";
            std::cin >> x;
            std::cout << "Enter the y-coordinate for planting: ";
            std::cin >> y;
            if (farm.addCrop(eggplant, x, y)) {
                crops[currentCropCount] = eggplant;
                currentCropCount++;
            } else {
                std::cout << "Failed to plant the wheat. Check if the coordinates are valid." << std::endl;
                delete eggplant;
            }
        //if the user entered "Beetroot"...
        } else if (cropToPlant == cropOptions[5]) {
            Beetroot* beetroot = new Beetroot("Beetroot", "Autumn", 6);
            int x, y;
            std::cout << "Enter the x-coordinate for planting: ";
            std::cin >> x;
            std::cout << "Enter the y-coordinate for planting: ";
            std::cin >> y;
            if (farm.addCrop(beetroot, x, y)) {
                crops[currentCropCount] = beetroot;
                currentCropCount++;
            } else {
                std::cout << "Failed to plant the beetroot. Check if the coordinates are valid." << std::endl;
                delete beetroot;
            }
        } else {
            std::cout << "Invalid crop" << std::endl;
        }
        //ask the user if they would like to input more crops
        std::string input;
        std::cout << "Would you like to plant another crop? (yes/no): ";
        std::cin >> input;
        if (input != "yes" && input != "Yes" && input != "YES") {
            continuePlanting = false;
        }
    }
    //display information about all crops in the farm
    farm.getAllCropsInfo();
    farm.visualizeFarmField();
    //example of how a crop can be removed. this can be implemented into the farm.removeCrop function later.
    std::cout << "Let's remove a crop." << std::endl << "Enter the x-coordinate for the crop you would like to remove: ";
    std::cin >> x;
    std::cout << "Enter the y-coordinate for this crop: ";
    std::cin >> y;
    Crop*** farmField = farm.getFarmField();
    Crop* cropToRemove = farmField[x][y];
    farm.removeCrop(cropToRemove);
    farm.visualizeFarmField();
    //(assuming the user entered a valid location)
    std::cout << "The crop has been removed." << std::endl;
    return 0;
}
