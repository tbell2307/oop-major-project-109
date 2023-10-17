#ifndef TIME_H
#define TIME_H

#include <string>
#include <vector>

class Time
{
private:
    int currentDay;
    int currentSeasonIndex;
    std::vector<std::string> seasons{"Spring", "Summer", "Autumn", "Winter"};

public:
    Time(int currDay);
    void passDay();
    int getCurrentDay() const;
    std::string getCurrentDayStr() const;
    std::string getCurrentSeason() const;
};

#endif
