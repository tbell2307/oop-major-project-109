//Cabbage.cpp
#include "Cabbage.hpp"

//constructor
Cabbage::Cabbage() : m_name("Cabbage"), m_sellprice(260.00), m_seedprice(100.00), m_growing_time(9), m_decay_time(4) {}

//destructor
Cabbage::~Cabbage() {}

//get the name
std::string Cabbage::getName(){
    return m_name;
}

//get the sell price
double Cabbage::getSellPrice() {
    return m_sellprice;
}

//get the seed price
double Cabbage::getSeedPrice() {
    return m_seedprice;
}

//get the growing time
int Cabbage::getGrowingTime() {
    return m_growing_time;
}

//get the decay time
int Cabbage::getDecayTime() {
    return m_decay_time;
}

//set the X-coordinate
void Cabbage::setX(int x) {
    X = x;
}

//get the X-coordinate
int Cabbage::getX() {
    return X;
}

//set the Y-coordinate
void Cabbage::setY(int y) {
    Y = y;
}

//get the Y-coordinate
int Cabbage::getY() {
    return Y;
}
