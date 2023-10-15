//Beetroot.cpp
#include "Beetroot.hpp"

//constructor
Beetroot::Beetroot() : m_name("Beetroot"), m_sellprice(100.00), m_seedprice(20.00), m_growing_time(6), m_decay_time(3) {}

//destructor
Beetroot::~Beetroot() {}

//get the name
std::string Beetroot::getName(){
    return m_name;
}

//get the sell price
double Beetroot::getSellPrice() {
    return m_sellprice;
}

//get the seed price
double Beetroot::getSeedPrice() {
    return m_seedprice;
}

//get the growing time
int Beetroot::getGrowingTime() {
    return m_growing_time;
}

//get the decay time
int Beetroot::getDecayTime() {
    return m_decay_time;
}

//set the X-coordinate
void Beetroot::setX(int x) {
    X = x;
}

//get the X-coordinate
int Beetroot::getX() {
    return X;
}

//set the Y-coordinate
void Beetroot::setY(int y) {
    Y = y;
}

//get the Y-coordinate
int Beetroot::getY() {
    return Y;
}
