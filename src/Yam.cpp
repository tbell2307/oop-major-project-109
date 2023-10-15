//Yam.cpp
#include "Yam.hpp"

//constructor
Yam::Yam() : m_name("Yam"), m_sellprice(160.00), m_seedprice(60.00), m_growing_time(10), m_decay_time(5) {}

//destructor
Yam::~Yam() {}

//get the name
std::string Yam::getName(){
    return m_name;
}

//get the sell price
double Yam::getSellPrice() {
    return m_sellprice;
}

//get the seed price
double Yam::getSeedPrice() {
    return m_seedprice;
}

//get the growing time
int Yam::getGrowingTime() {
    return m_growing_time;
}

//get the decay time
int Yam::getDecayTime() {
    return m_decay_time;
}

//set the X-coordinate
void Yam::setX(int x) {
    X = x;
}

//get the X-coordinate
int Yam::getX() {
    return X;
}

//set the Y-coordinate
void Yam::setY(int y) {
    Y = y;
}

//get the Y-coordinate
int Yam::getY() {
    return Y;
}
