#include <iostream>
#include "Bankomat.h"

int main() {
    Bankomat y(1500);
    y.statement();
    y.withdraw(1000);
    y.statement();
}