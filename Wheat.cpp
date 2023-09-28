//Wheat.cpp
#include "Wheat.hpp"

//default constructor
Wheat::Wheat() {}

//parameterised constructor
Wheat::Wheat(std::string name, std::string harvest_season,int growing_time) : Crop(name, harvest_season, growing_time), m_sellprice(25.00), m_decay_time(16), m_seedprice(10.00) {}

//destructor
Wheat::~Wheat() {}

//getter for sell price
double Wheat::getSellPrice(){
    return m_sellprice;
}

//getter for seed price
double Wheat::getSeedPrice(){
    return m_seedprice;
}

//getter for decay time
int Wheat::getDecayTime(){
    return m_decay_time;
}

//setter for x-coordinate
void Wheat::setX(int x){
    X = x;
}

//getter for x-coordinate
int Wheat::getX(){
    return X;
}

//setter for y-coordinate
void Wheat::setY(int y){
    Y = y;
}

//getter for y-coordinate
int Wheat::getY(){
    return Y;
}
