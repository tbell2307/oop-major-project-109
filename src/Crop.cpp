//Crop.cpp 
#include "Crop.hpp"

//default constructor
Crop::Crop() : m_age(0), m_mature(false), m_harvested(false), m_decayed(false) {}

//destructor
Crop::~Crop() {}

//increment the age 
void Crop::incrementAge() {
    m_age++;
}

//get the age 
int Crop::getAge() {
    return m_age;
}

//get the maturity 
bool Crop::isMature(){
    return m_mature;
}

//set the maturity 
void Crop::setMature(bool mature){
    m_mature = mature;
}

bool Crop::isHarvested(){
    return m_harvested;
}

void Crop::setHarvested(bool harvested){
    m_harvested = harvested;
}

bool Crop::isDecayed(){
    return m_decayed;
}

void Crop::setDecayed(bool decayed){
    m_decayed = decayed;
}