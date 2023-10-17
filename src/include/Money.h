#ifndef MONEY_H
#define MONEY_H

class Money
{
private:
    int amount;

public:
    Money(int initialAmount);
    void addAmount(int value);
    void subtractAmount(int value);
    int getAmount() const;
};

#endif
