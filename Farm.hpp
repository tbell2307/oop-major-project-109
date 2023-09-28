//Farm.hpp
#pragma once
#include "Crop.hpp"
#include <string>

class Farm {
private:
    Crop*** farmField; //2d array to represent the field, inside which crops are planted
    std::string m_name; //name of the farm
    std::string m_location; //location of the farm
    int m_x_dim; //x dimension of the field
    int m_y_dim; //y dimsension of the field
    int m_max_crops; //max number of crops in the field
    int m_current_crops; //current number of crops in the field

public:
    //constructors and destructor
    Farm();
    Farm(std::string name, std::string location, int x_dim, int y_dim);
    ~Farm();
    //getters
    std::string getName();
    std::string getLocation();
    int getXDim();
    int getYDim();
    int getMaxCrops();
    int getCurrentCrops();
    Crop*** getFarmField(); //getter for the field array
    //main member functions
    bool addCrop(Crop* crop, int x, int y);
    bool removeCrop(Crop* crop);
    void getAllCropsInfo();
    void visualizeFarmField();
};
