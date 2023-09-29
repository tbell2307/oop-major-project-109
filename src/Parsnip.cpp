//Parsnip.cpp
#include "Parsnip.hpp"

//default constructor
Parsnip::Parsnip() {}

//parameterised constructor
Parsnip::Parsnip(std::string name, std::string harvest_season,int growing_time) : Crop(name, harvest_season, growing_time), m_sellprice(35.00), m_decay_time(11), m_seedprice(20.00) {}

//destructor
Parsnip::~Parsnip() {}

//getter for sell price
double Parsnip::getSellPrice(){
    return m_sellprice;
}

//getter for seed price
double Parsnip::getSeedPrice(){
    return m_seedprice;
}

//getter for decay time
int Parsnip::getDecayTime(){
    return m_decay_time;
}

//setter for x-coordinate
void Parsnip::setX(int x){
    X = x;
}

//getter for x-coordinate
int Parsnip::getX(){
    return X;
}

//setter for y-coordinate
void Parsnip::setY(int y){
    Y = y;
}

//getter for y-coordinate
int Parsnip::getY(){
    return Y;
}
