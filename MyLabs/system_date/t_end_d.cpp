#include "t_end_d.h"

t_end_d::t_end_d(struct tm *timeinfo){
    year = timeinfo->tm_year + 1900;
    month = timeinfo->tm_mon + 1;
    day = timeinfo->tm_mday;
    min = timeinfo->tm_min;
    hour = timeinfo->tm_hour;
    sec = timeinfo->tm_sec;
}

t_end_d::t_end_d() {
    year = 0;
    month = 0;
    day = 0;
    min = 0;
    hour = 0;
    sec = 0;
}

t_end_d::t_end_d(t_end_d &date){
    day = date.day;
    month = date.month;
    year = date.year;
    sec = date.sec;
    hour = date.hour;
    min = date.min;
}

void t_end_d::getDate() {
    std::cout<<"Сейчас: "<<std::endl;
    std::cout<<day<<"."<<month<<"."<<year<<" "<<hour<<":"<<min<<":"<<sec;
    std::cout<<std::endl;
}

t_end_d::~t_end_d() {}