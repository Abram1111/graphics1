#ifndef CIRCLE_H
#define CIRCLE_H
#include"Shape.h"
class Circle : public Shape {

private:
    double radius;
      double perimeter;
public:
    void Setredius(double radius) ;

    double getredius() ;
    void Setperimeter(double radius) ;
    double getperimer() ;


};
#endif // CIRCLE_H
