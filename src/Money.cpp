#include "include/Money.h"

Money::Money(int initialAmount) : amount(initialAmount) {}

void Money::addAmount(int value)
{
    amount += value;
}

void Money::subtractAmount(int value)
{
    amount -= value;
}

int Money::getAmount() const
{
    return amount;
}
