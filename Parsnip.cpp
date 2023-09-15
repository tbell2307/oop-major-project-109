#include "Parsnip.hpp"

Parsnip::Parsnip()
{
}

Parsnip::Parsnip(std::string name,
                 std::string harvest_season,
                 int growing_time,
                 double sellprice)
    : Crop(name, harvest_season, growing_time), m_sellprice(12.00), m_decay_time(11), m_seedprice(2.0)
{
}

Parsnip::~Parsnip()
{
}