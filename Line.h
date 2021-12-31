#ifndef LINE_H
#define LINE_H
#include"Shape.h"
class Line : public Shape {

private:
    double length;
public:
    void Setlength(int x_f, int y_f, int x_s ,int y_s) ;
    double getlength() ;
};
#endif // LINE_H
