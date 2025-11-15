#ifndef POINT_H
#define POINT_H

class Point {
private:
    double x;
    double y;

public:
    Point(double x = 0, double y = 0);
    virtual ~Point();

    double GetX() const;
    double GetY() const;
};

#endif
