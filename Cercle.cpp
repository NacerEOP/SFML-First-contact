#include "Cercle.h"
#include <iostream>
#include <cmath>

Cercle::Cercle(Point centre, double rayon)
    : centre(centre), rayon(rayon) {}

Cercle::~Cercle() {}

Point Cercle::GetCentre() const { return centre; }
double Cercle::GetRayon() const { return rayon; }

void Cercle::Dessiner() const {
    std::cout << "Cercle: centre(" << centre.GetX() << ", "
              << centre.GetY() << "), rayon=" << rayon << std::endl;
}

double Cercle::Perimetre() const {
    return 2 * M_PI * rayon;
}

double Cercle::Aire() const {
    return M_PI * rayon * rayon;
}
