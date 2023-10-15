//AutumnCrop.cpp
#include "AutumnCrop.hpp"

//constructor for summer crops
AutumnCrop::AutumnCrop() : maximum_temp(30), minimum_temp(5), season("Autumn") {}

//destructor for summer crops
AutumnCrop::~AutumnCrop() {}

//get the maximum temperature for summer crops
int AutumnCrop::getMaximumTemp() {
    return maximum_temp;
}

//get the minimum temperature for summer crops
int AutumnCrop::getMinimumTemp() {
    return minimum_temp;
}

//get the season for summer crops
std::string AutumnCrop::getSeason() {
    return season;
}
