//Inventory.hpp
#pragma once
#include "Crop.hpp"
#include <iostream>

class Inventory {
private:
    Crop** inventoryCrops;
    int current_size;
    int maximum_size;
public:
    Inventory();
    ~Inventory();
    //accessors
    bool canAddCrop();
    bool addCrop(Crop* crop);
    void removeCrop(Crop* crop, int index);
    Crop* findCrop(std::string name);
    int findCropIndex(std::string name);
    void displayInventory();
};