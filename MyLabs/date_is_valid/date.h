#ifndef DATE_IS_VALID_DATE_H
#define DATE_IS_VALID_DATE_H

#include <iostream>
#include <ctime>

class Date{
private:
    unsigned short int day;
    unsigned short month;
    int year;
    void DateException(bool );
    void isValid();
public:
    Date();
    Date(unsigned short int, unsigned short int, int);
    Date(Date &);
    void getDate();
    ~Date();

};

#endif
