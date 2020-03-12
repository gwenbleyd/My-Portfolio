#ifndef ATM_BANKOMAT_H
#define ATM_BANKOMAT_H

#include "Money.h"

class Bankomat {
private:
    Money numberBills;
public:
    Bankomat(int money): numberBills(money){};
    void replenish(int);
    int withdraw(int);
    void statement();
};

#endif
