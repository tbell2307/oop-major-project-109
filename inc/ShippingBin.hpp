//ShippingBin.hpp
#pragma once
#include "Farm.hpp"
#include "Crop.hpp"
#include <iostream>

class ShippingBin {
private:
    Crop** harvestedCrops;
    int m_size;
public:
    ShippingBin();
    ~ShippingBin();
    int getSize();
    void increaseSize();
    void reset();
    Crop** getHarvestedCrops();
};