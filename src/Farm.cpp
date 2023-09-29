//Farm.cpp
#include "Farm.hpp"
#include <iostream>

//default constructor
Farm::Farm()
    : m_name("invalid name"), m_location("invalid location"), m_x_dim(3), m_y_dim(3), m_max_crops(m_x_dim * m_y_dim), m_current_crops(0) {
    farmField = new Crop**[m_x_dim];
    for (int i = 0; i < m_x_dim; i++) {
        farmField[i] = new Crop*[m_y_dim];
        for (int j = 0; j < m_y_dim; j++) {
            farmField[i][j] = nullptr;
        }
    }
}

//parameterised constructor
Farm::Farm(std::string name, std::string location, int x_dim, int y_dim)
    : m_name(name), m_location(location), m_x_dim(x_dim), m_y_dim(y_dim), m_max_crops(x_dim * y_dim), m_current_crops(0) {
    farmField = new Crop**[m_x_dim];
    for (int i = 0; i < m_x_dim; i++) {
        farmField[i] = new Crop*[m_y_dim];
        for (int j = 0; j < m_y_dim; j++) {
            farmField[i][j] = nullptr;
        }
    }
}

//destructor
Farm::~Farm() {
    delete[] farmField;
}

//getter for name
std::string Farm::getName() {
    return m_name;
}

//getter for location
std::string Farm::getLocation() {
    return m_location;
}

//getter for x_dim
int Farm::getXDim(){
    return m_x_dim;
}

//getter for y_dim
int Farm::getYDim(){
    return m_y_dim;
}

//getter for max_crops
int Farm::getMaxCrops() {
    return m_max_crops;
}

//getter for current_crops
int Farm::getCurrentCrops() {
    return m_current_crops;
}

//getter for farmField
Crop*** Farm::getFarmField() {
    return farmField;
}

//add a crop to farmField at the desired location
bool Farm::addCrop(Crop* crop, int x, int y) {
    if (x >= 0 && x < m_x_dim && y >= 0 && y < m_y_dim) {
        if (farmField[x][y] == nullptr) {
            farmField[x][y] = crop;
            crop->setX(x);
            crop->setY(y);
            m_current_crops++;
            return true;
        } else {
            std::cout << "A crop already exists at that location." << std::endl;
        }
    } else {
        std::cout << "Invalid coordinates. Please choose a valid location." << std::endl;
    }
    return false;
}

//remove a crop in farmField
bool Farm::removeCrop(Crop* crop) {
    for (int i = 0; i < m_x_dim; i++) {
        for (int j = 0; j < m_y_dim; j++) {
            if (farmField[i][j] == crop) {
                delete farmField[i][j];
                farmField[i][j] = nullptr;
                m_current_crops--;
                return true;
            }
        }
    }
    return false;
}

//print all information for a crop
void Farm::getAllCropsInfo() {
    std::cout << "------------------------" << std::endl;
    std::cout << "Crop data for " << getName() << "." << std::endl;
    if (m_current_crops > 0) {
        std::cout << "------------" << std::endl;
        for (int i = 0; i < m_x_dim; i++) {
            for (int j = 0; j < m_y_dim; j++) {
                if (farmField[i][j] != nullptr) {
                    std::cout << "Crop at location (" << i << ", " << j << ")..." << std::endl;
                    std::cout << "Name: " << farmField[i][j]->getName() << std::endl;
                    std::cout << "Harvest season: " << farmField[i][j]->getHarvestSeason() << std::endl;
                    std::cout << "Growing time: " << farmField[i][j]->getGrowingTime() << std::endl;
                    std::cout << "Sell price: " << farmField[i][j]->getSellPrice() << std::endl;
                    std::cout << "Seed price: " << farmField[i][j]->getSeedPrice() << std::endl;
                    std::cout << "Decay time: " << farmField[i][j]->getDecayTime() << std::endl;
                    std::cout << "X coordinate is: " << farmField[i][j]->getX() << std::endl;
                    std::cout << "Y coordinate is: " << farmField[i][j]->getY() << std::endl;
                    std::cout << "------------" << std::endl;
                }
            }
        }
    } else {
        std::cout << "No crop data exists." << std::endl;
        std::cout << "------------------------" << std::endl;
    }
}

//print a map of farmField
void Farm::visualizeFarmField() {
    std::cout << "Visualizing your farm field..." << std::endl;
    for (int j = 0; j < m_y_dim; j++) {
        for (int i = 0; i < m_x_dim; i++) {
            if (farmField[i][j] != nullptr) { //print a letter corresponding to the type of crop planted in that slot
                if (farmField[i][j]->getName() == "Parsnip") {
                    std::cout << "P ";
                } else if (farmField[i][j]->getName() == "Kale") {
                    std::cout << "K ";
                } else if (farmField[i][j]->getName() == "Radish") {
                    std::cout << "R ";
                } else if (farmField[i][j]->getName() == "Wheat") {
                    std::cout << "W ";
                } else if (farmField[i][j]->getName() == "Eggplant") {
                    std::cout << "E ";
                } else if (farmField[i][j]->getName() == "Beetroot") {
                    std::cout << "B ";
                }
            } else { //print a . to indicate an empty slot
                std::cout << ". ";
            }
        }
        std::cout << std::endl;
    }
}

