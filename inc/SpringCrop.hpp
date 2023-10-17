//SpringCrop.hpp
//(derived class for spring crops)
#pragma once
#include "Crop.hpp"

class SpringCrop : public Crop {
private:
    int maximum_temp;
    int minimum_temp;
    std::string season;
public:
    //constructor and destructor
    SpringCrop(); 
    virtual ~SpringCrop(); 
    //accessors
    int getMaximumTemp();
    int getMinimumTemp();
    std::string getSeason();
};
