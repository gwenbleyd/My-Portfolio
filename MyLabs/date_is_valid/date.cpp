#include "date.h"

Date::Date() {
    year = 0;
    month = 0;
    day = 0;
}

Date::Date(unsigned short int d, unsigned short int m, int y) {
    day = d;
    month = m;
    year = y;
    isValid();
}

Date::Date(Date &date) {
    day = date.day;
    month = date.month;
    year = date.year;
}

Date::~Date() {}

void Date::DateException(bool flag) {
    try {
        if(flag){
            throw "Дата введена некорректно";
        }
        std::cout<<"Дата введена корректно"<<std::endl;
    }
    catch (const char *str){
        std::cout<<str<<std::endl;
        exit(0);
    }
}

void Date::getDate() {
    std::cout<<"Ваша дата: "<<day<<"."<<month<<"."<<year<<std::endl;
}

void Date::isValid() {
    int leapYear = year % 4;

    if ( day < 1 || day > 31 ) {
        DateException(1);
    }
    if ( month < 1 || month > 12 ) {
        DateException(1);
    }
    if ( month == 2 && day > 29 - leapYear ) {
        DateException(1);
    }
    if ((month == 1 || month == 3 || month == 5 || month == 7 || month == 8 || month == 10 | month == 12)
        && day > 31 ) {
        DateException(1);
    }
    if ((month == 4 || month == 6 || month == 9 || month == 11) && day > 30){
        DateException(1);
    }
    DateException(0);
}

