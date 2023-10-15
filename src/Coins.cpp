//Coins.cpp
#include "Coins.hpp"

Coins::Coins() : m_coins(500) {}

void Coins::addCoins(int coins){
    m_coins += coins;
}

void Coins::removeCoins(int coins){
    m_coins -= coins;
}

int Coins::getCoins(){
    return m_coins;
}