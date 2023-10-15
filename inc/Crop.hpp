//Crop.hpp 
//(abstract base class for all crops)
#pragma once
#include <string>

class Crop {
private:
    int m_age; //age measured in days passed since the crop was planted
    bool m_mature; //flag to track maturity
    bool m_harvested; //flag to track if the crop is harvested
    bool m_decayed;
public:
    //constructors and destructor
    Crop(); 
    virtual ~Crop(); 
    //accessors
    void incrementAge();
    int getAge();
    bool isMature(); 
    void setMature(bool mature); 
    bool isHarvested();
    void setHarvested(bool harvested);
    bool isDecayed();
    void setDecayed(bool decayed);
    //abstract methods to be implemented by derived classes
    virtual std::string getName() = 0;
    virtual std::string getSeason() = 0;
    virtual double getSellPrice() = 0;
    virtual double getSeedPrice() = 0;
    virtual int getDecayTime() = 0;
    virtual int getGrowingTime() = 0;
    virtual void setX(int x) = 0;
    virtual int getX() = 0;
    virtual void setY(int y) = 0;
    virtual int getY() = 0;
};
           