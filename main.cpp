#include "DrawingWindow.h"
#include "Cercle.h"
#include "Rectangle.h"
#include "Carre.h"
#include "Triangle.h"
#include <iostream>

#include "Polygone.h"  

int main() {
    DrawingWindow win(800, 600, 40.f);

    Cercle c({0,0}, 3);
    Rectangle r({-4,2}, {2,-1});
    Carre sq({3,3}, 2);
    Triangle t({0,0}, {4,0}, {2,3});
    
    // Create a custom polygon (pentagon)
    Polygone pentagone({
        Point{0, 2},
        Point{2, 0},
        Point{1, -2},
        Point{-1, -2},
        Point{-2, 0}
    });

    // Display shape info in console
    std::cout << "=== SHAPE INFORMATION ===" << std::endl;
    
    std::cout << "\nCercle:" << std::endl;
    c.Dessiner();
    std::cout << "Aire = " << c.Aire() << ", Perimetre = " << c.Perimetre() << std::endl;
    
    std::cout << "\nRectangle:" << std::endl;
    r.Dessiner();
    std::cout << "Aire = " << r.Aire() << ", Perimetre = " << r.Perimetre() << std::endl;
    
    std::cout << "\nCarre:" << std::endl;
    sq.Dessiner();
    std::cout << "Aire = " << sq.Aire() << ", Perimetre = " << sq.Perimetre() << std::endl;
    
    std::cout << "\nTriangle:" << std::endl;
    t.Dessiner();
    std::cout << "Aire = " << t.Aire() << ", Perimetre = " << t.Perimetre() << std::endl;
    
    std::cout << "\nPolygone (Pentagone):" << std::endl;
    pentagone.Dessiner();
    std::cout << "Aire = " << pentagone.Aire() << ", Perimetre = " << pentagone.Perimetre() << std::endl;
    
    std::cout << "\n=== OPENING GRAPHICAL WINDOW ===" << std::endl;

    // Add shapes to graphical window
    win.AddShape(&c);
    win.AddShape(&r);
    win.AddShape(&sq);
    win.AddShape(&t);
    win.AddShape(&pentagone);  // Add the polygon

    win.Run();

    return 0;
}