#ifndef POLYGONE_H
#define POLYGONE_H

#include "Forme.h"
#include "Point.h"
#include <vector>

class Polygone : public Forme {
private:
    std::vector<Point> points;

public:
    Polygone(const std::vector<Point>& points = {});
    virtual ~Polygone();

    void AddPoint(const Point& p);
    const std::vector<Point>& GetPoints() const;
    size_t GetNombrePoints() const;

    void Dessiner() const override;
    double Perimetre() const override;
    double Aire() const override;
};

#endif