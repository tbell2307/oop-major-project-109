//WinterCrop.cpp
#include "WinterCrop.hpp"

//constructor for summer crops
WinterCrop::WinterCrop() : maximum_temp(10), minimum_temp(-5), season("Winter") {}

//destructor for summer crops
WinterCrop::~WinterCrop() {}

//get the maximum temperature for summer crops
int WinterCrop::getMaximumTemp() {
    return maximum_temp;
}

//get the minimum temperature for summer crops
int WinterCrop::getMinimumTemp() {
    return minimum_temp;
}

//get the season for summer crops
std::string WinterCrop::getSeason() {
    return season;
}
