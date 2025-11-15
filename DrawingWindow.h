#ifndef DRAWING_WINDOW_H
#define DRAWING_WINDOW_H

#define SFML_STATIC
#include <SFML/Graphics.hpp>
#include <vector>
#include "Forme.h"
#include "Polygone.h"  // Add this line

class DrawingWindow {
private:
    sf::RenderWindow window;
    float scale;
    float originX, originY;
    std::vector<const Forme*> shapes;

    void drawAxes();
    void drawShape(const Forme* f);

public:
    DrawingWindow(int width = 800, int height = 600, float scale = 40.f);
    void AddShape(const Forme* f);
    void Run();
};

#endif
