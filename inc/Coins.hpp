//Coins.hpp
#pragma once

class Coins {
private:
    int m_coins;
public:
    Coins();
    void addCoins(int coins);
    void removeCoins(int coins);
    int getCoins();
};