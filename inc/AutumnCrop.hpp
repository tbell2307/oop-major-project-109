//AutumnCrop.hpp
//(derived class for autumn crops)
#pragma once
#include "Crop.hpp"

class AutumnCrop : public Crop {
private:
    int maximum_temp;
    int minimum_temp;
    std::string season;
public:
    //constructor and destructor
    AutumnCrop(); 
    virtual ~AutumnCrop(); 
    //accessors
    int getMaximumTemp();
    int getMinimumTemp();
    std::string getSeason();
};
