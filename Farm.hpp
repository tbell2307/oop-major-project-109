#pragma once

#include "Crop.hpp"

class Farm
{
private:
    Crop** crops;
public:
    Farm();
    ~Farm();
};
