<<<<<<< HEAD
#include "Time.h"

Time::Time() : currentDay(1), currentSeasonIndex(0) {}

void Time::passDay()
{
    currentDay++;
    if (currentDay > 28)
    {
        currentDay = 1;
        currentSeasonIndex = (currentSeasonIndex + 1) % seasons.size();
    }
}

std::string Time::getCurrentSeason() const
{
    return seasons[currentSeasonIndex];
}
int Time::getCurrentDay() const
{
    return currentDay;
}

std::string Time::getCurrentDayStr() const
{
    return "Day: " + std::to_string(currentDay);
}
=======
//Time.cpp
#include "Time.hpp"

Time::Time() : day(1), month(1), year(1), daysPassed(0) {}

int Time::getDay(){
    return day;
}

int Time::getMonth(){
    return month;
}

int Time::getYear(){
    return year;
}

int Time::getDaysPassed(){
    return daysPassed;
}

void Time::incrementDay(Farm* farm) {
    if (day+1 <= 30){
        day++;
        daysPassed++;
    } else if (day+1 > 30 && month+1 <= 12){
        month++;
        day = 1;
        daysPassed++;
    } else if (day+1 > 30 && month+1 > 12){
        year++;
        month = 1;
        day = 1;
        daysPassed++;
    }
    Crop*** farmField = farm->getFarmField();
        for (int i = 0; i < farm->getXDim(); i++) {
            for (int j = 0; j < farm->getYDim(); j++) {
                if (farmField[i][j] != nullptr) {
                    farmField[i][j]->incrementAge();
                }
            }
        }
}
>>>>>>> develop
