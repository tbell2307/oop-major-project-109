//Kale.cpp
#include "Kale.hpp"

//constructor
Kale::Kale() : m_name("Kale"), m_sellprice(110.00), m_seedprice(70.00), m_growing_time(6), m_decay_time(3) {}

//destructor
Kale::~Kale() {}

//get the name
std::string Kale::getName(){
    return m_name;
}

//get the sell price
double Kale::getSellPrice() {
    return m_sellprice;
}

//get the seed price
double Kale::getSeedPrice() {
    return m_seedprice;
}

//get the growing time
int Kale::getGrowingTime() {
    return m_growing_time;
}

//get the decay time
int Kale::getDecayTime() {
    return m_decay_time;
}

//set the X-coordinate
void Kale::setX(int x) {
    X = x;
}

//get the X-coordinate
int Kale::getX() {
    return X;
}

//set the Y-coordinate
void Kale::setY(int y) {
    Y = y;
}

//get the Y-coordinate
int Kale::getY() {
    return Y;
}
