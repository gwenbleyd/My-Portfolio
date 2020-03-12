#include "Bankomat.h"

void Bankomat::statement() {
    numberBills.print();
    std::cout<<"Всего денег: "<<numberBills.getAmountMoney()<<std::endl;
}

void Bankomat::replenish(int money) {
    numberBills.filling(money);
}

int Bankomat::withdraw(int money) {
    numberBills.withdrawal(money);
    return money;
}


