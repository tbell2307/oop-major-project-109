//Kale.cpp
#include "Kale.hpp"

//default constructor
Kale::Kale() {}

//parameterised constructor
Kale::Kale(std::string name, std::string harvest_season,int growing_time) : Crop(name, harvest_season, growing_time), m_sellprice(110.00), m_decay_time(11), m_seedprice(70.00) {}

//destructor
Kale::~Kale() {}

//getter for sell price
double Kale::getSellPrice(){
    return m_sellprice;
}

//getter for seed price
double Kale::getSeedPrice(){
    return m_seedprice;
}

//getter for decay time
int Kale::getDecayTime(){
    return m_decay_time;
}

//setter for x-coordinate
void Kale::setX(int x){
    X = x;
}

//getter for x-coordinate
int Kale::getX(){
    return X;
}

//setter for y-coordinate
void Kale::setY(int y){
    Y = y;
}

//getter for y-coordinate
int Kale::getY(){
    return Y;
}
