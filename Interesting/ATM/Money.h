#ifndef ATM_MONEY_H
#define ATM_MONEY_H

#include <tuple>
#include <vector>
#include <iostream>

class Money {
private:
    std::vector<std::tuple<int, int>> quantity;
    static void MoneyException(int);
    static void AmountException();
    void ArgumentException(int);
public:
    Money(int);
    double getAmountMoney();
    void print();
    void filling(int);
    void withdrawal(int);
    ~Money();
};


#endif
