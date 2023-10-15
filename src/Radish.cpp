// Radish.cpp
#include "Radish.hpp"

// default constructor
Radish::Radish() {}

// parameterised constructor
Radish::Radish(std::string name, std::string harvest_season, int growing_time) : Crop(), m_sellprice(90.00), m_decay_time(7), m_seedprice(40.00) {}

// destructor
Radish::~Radish() {}

// getter for sell price
double Radish::getSellPrice()
{
    return m_sellprice;
}

// getter for seed price
double Radish::getSeedPrice()
{
    return m_seedprice;
}

// getter for decay time
int Radish::getDecayTime()
{
    return m_decay_time;
}

// setter for x-coordinate
void Radish::setX(int x)
{
    X = x;
}

// getter for x-coordinate
int Radish::getX()
{
    return X;
}

// setter for y-coordinate
void Radish::setY(int y)
{
    Y = y;
}

// getter for y-coordinate
int Radish::getY()
{
    return Y;
}
