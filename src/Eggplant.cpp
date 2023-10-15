//Eggplant.cpp
#include "Eggplant.hpp"

//constructor
Eggplant::Eggplant() : m_name("Eggplant"), m_sellprice(60.00), m_seedprice(20.00), m_growing_time(5), m_decay_time(3) {}

//destructor
Eggplant::~Eggplant() {}

//get the name
std::string Eggplant::getName(){
    return m_name;
}

//get the sell price
double Eggplant::getSellPrice() {
    return m_sellprice;
}

//get the seed price
double Eggplant::getSeedPrice() {
    return m_seedprice;
}

//get the growing time
int Eggplant::getGrowingTime() {
    return m_growing_time;
}

//get the decay time
int Eggplant::getDecayTime() {
    return m_decay_time;
}

//set the X-coordinate
void Eggplant::setX(int x) {
    X = x;
}

//get the X-coordinate
int Eggplant::getX() {
    return X;
}

//set the Y-coordinate
void Eggplant::setY(int y) {
    Y = y;
}

//get the Y-coordinate
int Eggplant::getY() {
    return Y;
}
