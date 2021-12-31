#include"Line.h"
#include<cmath>
void Line:: Setlength(int x_f, int y_f, int x_s ,int y_s) {
    length = sqrt((x_f-x_s)^2+(y_f-y_s)^2);
}
double Line:: getlength() {
    return length;
}
