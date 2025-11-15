#ifndef CERCLE_H
#define CERCLE_H

#include "Forme.h"
#include "Point.h"

class Cercle : public Forme {
private:
    Point centre;
    double rayon;

public:
    Cercle(Point centre, double rayon);
    virtual ~Cercle();

    Point GetCentre() const;
    double GetRayon() const;

    void Dessiner() const override;
    double Perimetre() const override;
    double Aire() const override;
};

#endif
