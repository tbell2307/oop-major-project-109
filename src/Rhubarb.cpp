//Rhubarb.cpp
#include "Rhubarb.hpp"

//constructor
Rhubarb::Rhubarb() : m_name("Rhubarb"), m_sellprice(220.00), m_seedprice(100.00), m_growing_time(13), m_decay_time(7) {}

//destructor
Rhubarb::~Rhubarb() {}

//get the name
std::string Rhubarb::getName(){
    return m_name;
}

//get the sell price
double Rhubarb::getSellPrice() {
    return m_sellprice;
}

//get the seed price
double Rhubarb::getSeedPrice() {
    return m_seedprice;
}

//get the growing time
int Rhubarb::getGrowingTime() {
    return m_growing_time;
}

//get the decay time
int Rhubarb::getDecayTime() {
    return m_decay_time;
}

//set the X-coordinate
void Rhubarb::setX(int x) {
    X = x;
}

//get the X-coordinate
int Rhubarb::getX() {
    return X;
}

//set the Y-coordinate
void Rhubarb::setY(int y) {
    Y = y;
}

//get the Y-coordinate
int Rhubarb::getY() {
    return Y;
}
