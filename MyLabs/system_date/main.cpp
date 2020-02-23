#include "t_end_d.h"

int main() {
    time_t rawtime;
    struct tm * timeinfo;
    time (&rawtime);
    timeinfo = localtime (&rawtime);
    auto x = t_end_d(timeinfo);
    auto y = t_end_d(timeinfo);
    auto z = t_end_d(y);
    x.getDate();
    y.getDate();
    z.getDate();
    return 0;
}