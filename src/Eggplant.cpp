//Eggplant.cpp
#include "Eggplant.hpp"

//default constructor
Eggplant::Eggplant() {}

//parameterised constructor
Eggplant::Eggplant(std::string name, std::string harvest_season,int growing_time) : Crop(name, harvest_season, growing_time), m_sellprice(35.00), m_decay_time(9), m_seedprice(60.00) {}

//destructor
Eggplant::~Eggplant() {}

//getter for sell price
double Eggplant::getSellPrice(){
    return m_sellprice;
}

//getter for seed price
double Eggplant::getSeedPrice(){
    return m_seedprice;
}

//getter for decay time
int Eggplant::getDecayTime(){
    return m_decay_time;
}

//setter for x-coordinate
void Eggplant::setX(int x){
    X = x;
}

//getter for x-coordinate
int Eggplant::getX(){
    return X;
}

//setter for y-coordinate
void Eggplant::setY(int y){
    Y = y;
}

//getter for y-coordinate
int Eggplant::getY(){
    return Y;
}
