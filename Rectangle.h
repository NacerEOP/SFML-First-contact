#ifndef RECTANGLE_H
#define RECTANGLE_H

#include "Polygone.h"
#include "Point.h"

class Rectangle : public Polygone {
protected:
    Point p1, p2;

public:
    Rectangle(Point p1, Point p2);
    virtual ~Rectangle();

    Point GetP1() const;
    Point GetP2() const;

    void Dessiner() const override;
    double Perimetre() const override;
    double Aire() const override;
};

#endif
