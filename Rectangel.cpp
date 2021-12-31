#include"Rectangle.h"

    void Rectangle:: Setlength(double length) {
        this->length = length;
    }

    double Rectangle:: getlength() {
        return length;
    }
    void Rectangle:: Setwidth(double width) {
        this->width = width;
    }

    double Rectangle:: getwidth() {
        return width;
    }
    void Rectangle:: Setperimeter(double width, double length) {
         perimeter = 2 * (width + length);
    }

    double Rectangle:: getperimeter() {
        return perimeter ;
    }
