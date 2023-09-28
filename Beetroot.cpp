//Beetroot.cpp
#include "Beetroot.hpp"

//default constructor
Beetroot::Beetroot() {}

//parameterised constructor
Beetroot::Beetroot(std::string name, std::string harvest_season,int growing_time) : Crop(name, harvest_season, growing_time), m_sellprice(100.00), m_decay_time(5), m_seedprice(20.00) {}

//destructor
Beetroot::~Beetroot() {}

//getter for sell price
double Beetroot::getSellPrice(){
    return m_sellprice;
}

//getter for seed price
double Beetroot::getSeedPrice(){
    return m_seedprice;
}

//getter for decay time
int Beetroot::getDecayTime(){
    return m_decay_time;
}

//setter for x-coordinate
void Beetroot::setX(int x){
    X = x;
}

//getter for x-coordinate
int Beetroot::getX(){
    return X;
}

//setter for y-coordinate
void Beetroot::setY(int y){
    Y = y;
}

//getter for y-coordinate
int Beetroot::getY(){
    return Y;
}
