//SpringCrop.cpp
#include "SpringCrop.hpp"

//constructor for summer crops
SpringCrop::SpringCrop() : maximum_temp(25), minimum_temp(5), season("Spring") {}

//destructor for summer crops
SpringCrop::~SpringCrop() {}

//get the maximum temperature for summer crops
int SpringCrop::getMaximumTemp() {
    return maximum_temp;
}

//get the minimum temperature for summer cropss
int SpringCrop::getMinimumTemp() {
    return minimum_temp;
}

//get the season for summer crops
std::string SpringCrop::getSeason() {
    return season;
}
