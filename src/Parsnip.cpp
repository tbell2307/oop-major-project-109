//Parsnip.cpp
#include "Parsnip.hpp"

//constructor
Parsnip::Parsnip() : m_name("Parsnip"), m_sellprice(35.00), m_seedprice(20.00), m_growing_time(4), m_decay_time(2) {}

//destructor
Parsnip::~Parsnip() {}

//get the name
std::string Parsnip::getName(){
    return m_name;
}

//get the sell price
double Parsnip::getSellPrice() {
    return m_sellprice;
}

//get the seed price
double Parsnip::getSeedPrice() {
    return m_seedprice;
}

//get the growing time
int Parsnip::getGrowingTime() {
    return m_growing_time;
}

//get the decay time
int Parsnip::getDecayTime() {
    return m_decay_time;
}

//set the X-coordinate
void Parsnip::setX(int x) {
    X = x;
}

//get the X-coordinate
int Parsnip::getX() {
    return X;
}

//set the Y-coordinate
void Parsnip::setY(int y) {
    Y = y;
}

//get the Y-coordinate
int Parsnip::getY() {
    return Y;
}
