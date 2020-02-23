#ifndef SYSTEM_DATE_T_END_D_H
#define SYSTEM_DATE_T_END_D_H

#include <ctime>
#include <iostream>

class t_end_d {
private:
    int year;
    int month;
    int day;
    int min;
    int hour;
    int sec;
public:
    t_end_d(struct tm *);
    t_end_d();
    t_end_d(t_end_d &);
    void getDate();
    ~t_end_d();
};


#endif //SECOND_LAB_T_END_D_H
