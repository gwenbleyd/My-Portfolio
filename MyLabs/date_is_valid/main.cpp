#include "date.h"

int main() {
    auto x = Date(20,12,2020);
    auto y = Date(x);
    y.getDate();
    return 0;
}