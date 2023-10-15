//Wheat.cpp
#include "Wheat.hpp"

//constructor
Wheat::Wheat() : m_name("Wheat"), m_sellprice(25.00), m_seedprice(10.00), m_growing_time(4), m_decay_time(2) {}

//destructor
Wheat::~Wheat() {}

//get the name
std::string Wheat::getName(){
    return m_name;
}

//get the sell price
double Wheat::getSellPrice() {
    return m_sellprice;
}

//get the seed price
double Wheat::getSeedPrice() {
    return m_seedprice;
}

//get the growing time
int Wheat::getGrowingTime() {
    return m_growing_time;
}

//get the decay time
int Wheat::getDecayTime() {
    return m_decay_time;
}

//set the X-coordinate
void Wheat::setX(int x) {
    X = x;
}

//get the X-coordinate
int Wheat::getX() {
    return X;
}

//set the Y-coordinate
void Wheat::setY(int y) {
    Y = y;
}

//get the Y-coordinate
int Wheat::getY() {
    return Y;
}
