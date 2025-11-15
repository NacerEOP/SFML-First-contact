#include "Carre.h"
#include <iostream>

Carre::Carre(Point p, double cote)
    : p(p), cote(cote) {}

Carre::~Carre() {}

Point Carre::GetOrigine() const { return p; }
double Carre::GetCote() const { return cote; }

void Carre::Dessiner() const {
    std::cout << "Carre: origine(" << p.GetX() << ", "
              << p.GetY() << "), cote=" << cote << std::endl;
}

double Carre::Perimetre() const { return 4 * cote; }
double Carre::Aire() const { return cote * cote; }
