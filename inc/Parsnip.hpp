//Parsnip.hpp
#pragma once
#include "Crop.hpp"

class Parsnip : public Crop {
private:
    double m_sellprice; //nusmber of coins the crop will sell for
    double m_seedprice; //number of coins the seed costs to buy
    int m_decay_time; //number of days passed after the crop matures before it decays
    int X; //x-coordinate of the crop
    int Y; //y-coordinate of the crop
public:
    //constructors and destructor
    Parsnip();
    Parsnip(std::string name,std::string harvest_season,int growing_time);
    ~Parsnip();
    //getters and setters
    double getSellPrice();
    double getSeedPrice();
    int getDecayTime();
    void setX(int x);
    int getX();
    void setY(int y);
    int getY();
};

