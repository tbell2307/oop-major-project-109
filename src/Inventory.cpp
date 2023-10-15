//Inventory.cpp
#include "Inventory.hpp"

Inventory::Inventory() : current_size(0), maximum_size(10) {
    inventoryCrops = new Crop*[maximum_size];
    for (int i = 0; i < maximum_size; i++) {
        inventoryCrops[i] = nullptr;
    }
}

Inventory::~Inventory(){
    for (int i = 0; i < current_size; i++) {
        delete inventoryCrops[i];
    }
    delete[] inventoryCrops;
}

bool Inventory::canAddCrop(){
    if (current_size < maximum_size){
        return true;
    }
    return false;
}

bool Inventory::addCrop(Crop* crop){
    if (current_size < maximum_size){
        inventoryCrops[current_size] = crop;
        current_size++;
        return true;
    }
    return false;
}

void Inventory::removeCrop(Crop* crop, int index){
    crop = nullptr;
    for(int i = index; i < current_size; i++){
        inventoryCrops[i] = inventoryCrops[i+1];
    }
    current_size--;
}

Crop* Inventory::findCrop(std::string name){
    for (int i = 0; i < current_size; i++){
        if(inventoryCrops[i]->getName() == name){
            return inventoryCrops[i];
        }
    }
    return nullptr;
}

int Inventory::findCropIndex(std::string name){
    for (int i = 0; i < current_size; i++){
        if(inventoryCrops[i]->getName() == name){
            return i;
        }
    }
    return 0;
}

void Inventory::displayInventory() {
    if (current_size != 0){
        std::cout << "Inventory: ";
        for (int i = 0; i < current_size; i++) {
            std::cout << inventoryCrops[i]->getName() << "  ";
        }
        std::cout << std::endl;
    } else {
        std::cout << "There are no crops in your inventory." << std::endl;
    }
}