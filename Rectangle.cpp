#include "Rectangle.h"
#include <iostream>
#include <cmath>

Rectangle::Rectangle(Point p1, Point p2)
    : p1(p1), p2(p2) {}

Rectangle::~Rectangle() {}

Point Rectangle::GetP1() const { return p1; }
Point Rectangle::GetP2() const { return p2; }

void Rectangle::Dessiner() const {
    std::cout << "Rectangle: p1(" << p1.GetX() << ", " << p1.GetY()
              << "), p2(" << p2.GetX() << ", " << p2.GetY() << ")" << std::endl;
}

double Rectangle::Perimetre() const {
    double L = fabs(p2.GetX() - p1.GetX());
    double H = fabs(p2.GetY() - p1.GetY());
    return 2 * (L + H);
}

double Rectangle::Aire() const {
    double L = fabs(p2.GetX() - p1.GetX());
    double H = fabs(p2.GetY() - p1.GetY());
    return L * H;
}
