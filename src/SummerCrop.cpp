//SummerCrop.cpp
#include "SummerCrop.hpp"

//constructor for summer crops
SummerCrop::SummerCrop() : maximum_temp(35), minimum_temp(15), season("Summer") {}

//destructor for summer crops
SummerCrop::~SummerCrop() {}

//get the maximum temperature for summer crops
int SummerCrop::getMaximumTemp() {
    return maximum_temp;
}

//get the minimum temperature for summer crops
int SummerCrop::getMinimumTemp() {
    return minimum_temp;
}

//get the season for summer crops
std::string SummerCrop::getSeason() {
    return season;
}
