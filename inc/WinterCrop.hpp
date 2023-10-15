//WinterCrop.hpp
//(derived class for winter crops)
#pragma once
#include "Crop.hpp"

class WinterCrop : public Crop {
private:
    int maximum_temp;
    int minimum_temp;
    std::string season;
public:
    //constructor and destructor
    WinterCrop(); 
    virtual ~WinterCrop(); 
    //accessors
    int getMaximumTemp();
    int getMinimumTemp();
    std::string getSeason();
};
