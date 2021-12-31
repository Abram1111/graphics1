#ifndef RECTANGLE_H
#define RECTANGLE_H
#include"Shape.h"
class Rectangle : public Shape {

private:
    double length;
    double width;
    double perimeter;
public:
    void Setlength(double length) ;

    double getlength() ;
    void Setwidth(double width) ;

    double getwidth() ;
    void Setperimeter(double width, double length) ;
    double getperimeter() ;
};
#endif // RECTANGLE_H
