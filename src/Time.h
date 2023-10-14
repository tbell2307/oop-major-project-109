#ifndef TIME_H
#define TIME_H

#include <string>

class Time
{
private:
    int currentDay;

public:
    Time();
    void passDay();
    int getCurrentDay() const;
    std::string getCurrentDayStr() const;
};

#endif
