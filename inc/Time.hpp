//Time.hpp
#pragma once
#include "Farm.hpp"

class Time{
public:
    int day;
    int month;
    int year;
    int daysPassed;
    Time();
    int getDay();
    int getMonth();
    int getYear();
    int getDaysPassed();
    void incrementDay(Farm* farm);
};