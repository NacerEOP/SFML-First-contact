#ifndef CARRE_H
#define CARRE_H

#include "Polygone.h"
#include "Point.h"

class Carre : public Polygone {
private:
    Point p;
    double cote;

public:
    Carre(Point p, double cote);
    virtual ~Carre();

    Point GetOrigine() const;
    double GetCote() const;

    void Dessiner() const override;
    double Perimetre() const override;
    double Aire() const override;
};

#endif
