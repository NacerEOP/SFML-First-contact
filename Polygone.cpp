#include "Polygone.h"
#include <iostream>
#include <cmath>

Polygone::Polygone(const std::vector<Point>& points) : points(points) {}

Polygone::~Polygone() {}

void Polygone::AddPoint(const Point& p) {
    points.push_back(p);
}

const std::vector<Point>& Polygone::GetPoints() const {
    return points;
}

size_t Polygone::GetNombrePoints() const {
    return points.size();
}

void Polygone::Dessiner() const {
    std::cout << "Polygone: ";
    for (size_t i = 0; i < points.size(); ++i) {
        std::cout << "P" << i << "(" << points[i].GetX() << ", " << points[i].GetY() << ")";
        if (i < points.size() - 1) std::cout << ", ";
    }
    std::cout << std::endl;
}

double Polygone::Perimetre() const {
    if (points.size() < 3) return 0;
    
    double perimetre = 0;
    for (size_t i = 0; i < points.size(); ++i) {
        size_t next = (i + 1) % points.size();
        double dx = points[next].GetX() - points[i].GetX();
        double dy = points[next].GetY() - points[i].GetY();
        perimetre += sqrt(dx * dx + dy * dy);
    }
    return perimetre;
}

double Polygone::Aire() const {
    if (points.size() < 3) return 0;
    
    double aire = 0;
    for (size_t i = 0; i < points.size(); ++i) {
        size_t next = (i + 1) % points.size();
        aire += points[i].GetX() * points[next].GetY() - points[next].GetX() * points[i].GetY();
    }
    return fabs(aire) / 2.0;
}