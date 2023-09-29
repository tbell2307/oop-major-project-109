//Crop.hpp
#pragma once
#include <string>

class Crop {
private:
    std::string m_name; //name of the crop
    std::string m_harvest_season; //season in which the crop can be harvested
    int m_growing_time; //number of days the crop takes to grow from a seed to full maturity

public:
    //constructors and destructor
    Crop();
    Crop(std::string name, std::string harvest_season, int growing_time);
    ~Crop();
    //getters and setters
    std::string getName();
    std::string getHarvestSeason();
    void setHarvestSeason(std::string harvest_season);
    int getGrowingTime();
    //virtual functions
    virtual double getSellPrice();
    virtual double getSeedPrice();
    virtual int getDecayTime();
    virtual void setX(int x);
    virtual int getX();
    virtual void setY(int y);
    virtual int getY();    
};
