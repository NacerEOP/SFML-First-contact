#ifndef FORME_H
#define FORME_H

class Forme {
public:
    Forme() {}
    virtual ~Forme() {}

    virtual void Dessiner() const = 0;
    virtual double Perimetre() const = 0;
    virtual double Aire() const = 0;
};

#endif
