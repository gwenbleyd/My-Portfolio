#include "Money.h"

Money::Money(int money) {
    MoneyException(money);
    quantity.emplace_back(10,0);
    for (int i = 1; i < 6; i++){
        if ( i % 2 != 0)
            quantity.emplace_back(std::get<0>(quantity[i-1])*5,0);
        else
            quantity.emplace_back(std::get<0>(quantity[i-1])*2,0);
    }
    filling(money);
}

double Money::getAmountMoney() {
    int totalMoney = 0;
    for (int i = 0; i < 6; i++){
        totalMoney += std::get<0>(quantity[i]) * std::get<1>(quantity[i]);
    }
    return totalMoney;
}

void Money::print() {
    for (int i = 0; i < 6; i++) {
        std::cout<<"Купюр наминалом "<< std::get<0>(quantity[i]) <<" рублей "<< std::get<1>(quantity[i])<<" штук"<<std::endl;
    }
}

void Money::filling(int money) {
    while (money != 0){
        if(money >= 5000){
            money -= 5000;
            std::get<1>(quantity[5])++;
        }
        if (money >= 1000){
            money -= 1000;
            std::get<1>(quantity[4])++;
        }
        if(money >= 500){
            money -= 500;
            std::get<1>(quantity[3])++;
        }
        if(money >= 100){
            money -= 100;
            std::get<1>(quantity[2])++;
        }
        if(money >= 50){
            money -= 50;
            std::get<1>(quantity[1])++;
        }
        if(money >= 10){
            money -= 10;
            std::get<1>(quantity[0])++;
        }
    }
}

void Money::withdrawal(int money) {
    ArgumentException(money);
    int n = 0;
    auto tmp = quantity;
    if(money >= 5000 && std::get<1>(tmp[5]) != 0){
        n = money / 5000;
        if (std::get<1>(tmp[5]) >= n){
            money -= n*5000;
            std::get<1>(tmp[5])-=n;
        }
    }
    if (money >= 1000 && std::get<1>(tmp[4]) != 0){
        n = money / 1000;
        if (std::get<1>(tmp[4]) >= n){
            money -= n*1000;
            std::get<1>(tmp[4])-=n;
        }
    }
    if(money >= 500 && std::get<1>(tmp[3]) != 0){
        n = money / 500;
        if (std::get<1>(tmp[3]) >= n){
            money -= n*500;
            std::get<1>(tmp[3])-=n;
        }
    }
    if(money >= 100 && std::get<1>(tmp[2]) != 0){
        n = money / 100;
        if (std::get<1>(tmp[2]) >= n){
            money -= n*100;
            std::get<1>(tmp[2])-=n;
        }
    }
    if(money >= 50 && std::get<1>(tmp[1]) != 0){
        n = money / 50;
        if (std::get<1>(tmp[1]) >= n){
            money -= n*50;
            std::get<1>(tmp[1])-=n;
        }
    }
    if(money >= 10 && std::get<1>(tmp[0]) != 0){
        n = money / 10;
        if (std::get<1>(tmp[0]) >= n){
            money -= n*10;
            std::get<1>(tmp[0])-=n;
        }
    }
    if(money != 0){
        AmountException();
    } else{
        quantity = tmp;
    }
}

void Money::AmountException() {
    try {
        throw "Такая сумма не может быть выдаана";
    }
    catch (const char *str){
        std::cout<<str<<std::endl;
        exit(0);
    }
}

void Money::ArgumentException(int money) {
    try {
        if(getAmountMoney() == 0)
            throw "Счет пуст";
        if (money % 10 != 0 || money < 0 || money > getAmountMoney())
            throw "Такая сумма не может быть выдаана";
    }
    catch (const char *str){
        std::cout<<str<<std::endl;
        exit(0);
    }
}

void Money::MoneyException(int money) {
    try {
        if(money < 0 || money % 10 != 0)
            throw "Сумма введена неккоректно";
    }
    catch (const char *str){
        std::cout<<str<<std::endl;
        exit(0);
    }
}

Money::~Money()= default;