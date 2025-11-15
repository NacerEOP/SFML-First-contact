#include "Point.h"

Point::Point(double x, double y) : x(x), y(y) {}
Point::~Point() {}

double Point::GetX() const { return x; }
double Point::GetY() const { return y; }
