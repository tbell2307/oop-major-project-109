#include "include/Time.h"

Time::Time(int currDay) : currentDay(currDay), currentSeasonIndex(0) {}

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
