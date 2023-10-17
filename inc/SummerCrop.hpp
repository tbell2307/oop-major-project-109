//SummerCrop.hpp
//(derived class for summer crops)
#pragma once
#include "Crop.hpp"

class SummerCrop : public Crop {
private:
    int maximum_temp;
    int minimum_temp;
    std::string season;
public:
    //constructor and destructor
    SummerCrop(); 
    virtual ~SummerCrop(); 
    //accessors
    int getMaximumTemp();
    int getMinimumTemp();
    std::string getSeason();
};
