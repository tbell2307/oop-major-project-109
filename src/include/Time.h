#ifndef TIME_H
#define TIME_H

#include <string>

class Time
{
private:
    int currentDay;
    int currentSeasonIndex;
    std::vector<std::string> seasons{"Spring", "Summer", "Autumn", "Winter"};

public:
    Time();
    void passDay();
    int getCurrentDay() const;
    std::string getCurrentDayStr() const;
    std::string getCurrentSeason() const;
};

#endif
