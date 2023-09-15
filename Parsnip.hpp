#pragma once

#include "Crop.hpp"

class Parsnip : public Crop
{
private:
    double m_sellprice;
    double m_seedprice;
    int m_decay_time;

public:
    Parsnip();
    Parsnip(std::string name,
            std::string harvest_season,
            int growing_time,
            double sellprice);

    ~Parsnip();
};
