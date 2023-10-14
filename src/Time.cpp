#include "Time.h"

Time::Time() : currentDay(1) {}

void Time::passDay()
{
    currentDay++;
}

int Time::getCurrentDay() const
{
    return currentDay;
}

std::string Time::getCurrentDayStr() const
{
    return "Day: " + std::to_string(currentDay);
}
