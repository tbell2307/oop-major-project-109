//Parsnip.hpp
//(derived class for Parsnip crop)
#pragma once
#include "SpringCrop.hpp"
#include <string>

class Parsnip : public SpringCrop {
private:
    std::string m_name;
    double m_sellprice; //sell price 
    double m_seedprice; //seed price 
    int m_growing_time; //growing time 
    int m_decay_time; //decay time 
    int X; //x-coordinate 
    int Y; //y-coordinate 
public:
    //constructor and destructor
    Parsnip(); 
    virtual ~Parsnip(); 
    //implement abstract methods from the base class
    std::string getName() override;
    double getSellPrice() override;
    double getSeedPrice() override;
    int getGrowingTime() override;
    int getDecayTime() override;
    void setX(int x) override;
    int getX() override;
    void setY(int y) override;
    int getY() override;
};
