//Crop.cpp
#include "Crop.hpp"

//default constructor
Crop::Crop() {}

//parameterised constructor
Crop::Crop(std::string name, std::string harvest_season, int growing_time) : m_growing_time(growing_time), m_name(name), m_harvest_season(harvest_season) {}

//destructor
Crop::~Crop() {}

//getter for name
std::string Crop::getName() {
    return m_name;
}

//getter for harvest season
std::string Crop::getHarvestSeason() {
    return m_harvest_season;
}

//setter for harvest season
void Crop::setHarvestSeason(std::string harvest_season) {
    m_harvest_season = harvest_season;
}

//getter for growing time
int Crop::getGrowingTime() {
    return m_growing_time;
}

//virtual function - getter for sell price
double Crop::getSellPrice(){
    return 0;
}

//virtual function - getter for seed price
double Crop::getSeedPrice(){
    return 0;
}

//virtual function - getter for decay time
int Crop::getDecayTime(){
    return 0;
}

//virtual function - setter for the x-coordinate of the crop
void Crop::setX(int x){
}

//virtual function - getter for the x-coordinate of the crop
int Crop::getX(){
    return 0;
}

//virtual function - setter for the y-coordinate of the crop
void Crop::setY(int y){
}

//virtual function - getter for the y-coordinate of the crop
int Crop::getY(){
    return 0;
}