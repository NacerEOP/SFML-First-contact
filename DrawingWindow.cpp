#include <cmath>
#include "DrawingWindow.h"
#include "Cercle.h"
#include "Rectangle.h"
#include "Carre.h"
#include "Triangle.h"

DrawingWindow::DrawingWindow(int width, int height, float scale) 
    : window(sf::VideoMode(sf::Vector2u(width, height)), "Coordinate Viewer"), scale(scale) 
{
    originX = width / 2.f;
    originY = height / 2.f;
}

void DrawingWindow::AddShape(const Forme* f) {
    shapes.push_back(f);
}

void DrawingWindow::drawAxes() {
    sf::Vertex xAxis[2] = { 
        { sf::Vector2f(0, originY), sf::Color::White }, 
        { sf::Vector2f(window.getSize().x, originY), sf::Color::White } 
    };
    sf::Vertex yAxis[2] = { 
        { sf::Vector2f(originX, 0), sf::Color::White }, 
        { sf::Vector2f(originX, window.getSize().y), sf::Color::White } 
    };
    window.draw(xAxis, std::size(xAxis), sf::PrimitiveType::Lines);
    window.draw(yAxis, std::size(yAxis), sf::PrimitiveType::Lines);
}

void DrawingWindow::drawShape(const Forme* f) {
    // CIRCLE
    if (auto c = dynamic_cast<const Cercle*>(f)) {
        float r = c->GetRayon();
        sf::CircleShape shape(r * scale);
        shape.setFillColor(sf::Color::Transparent);
        shape.setOutlineColor(sf::Color::Red);
        shape.setOutlineThickness(2);
        shape.setPosition(sf::Vector2f(
            originX + c->GetCentre().GetX()*scale - r*scale,
            originY - c->GetCentre().GetY()*scale - r*scale
        ));
        window.draw(shape);
        return;
    }

    // RECTANGLE
    if (auto r = dynamic_cast<const Rectangle*>(f)) {
        Point p1 = r->GetP1();
        Point p2 = r->GetP2();
        float w = std::fabs(p2.GetX() - p1.GetX()) * scale;
        float h = std::fabs(p2.GetY() - p1.GetY()) * scale;
        sf::RectangleShape shape(sf::Vector2f(w, h));
        shape.setFillColor(sf::Color::Transparent);
        shape.setOutlineColor(sf::Color::Green);
        shape.setOutlineThickness(2);
        shape.setPosition(sf::Vector2f(
            originX + p1.GetX()*scale,
            originY - p1.GetY()*scale - h
        ));
        window.draw(shape);
        return;
    }

    // SQUARE
    if (auto sq = dynamic_cast<const Carre*>(f)) {
        float c = sq->GetCote();
        Point p = sq->GetOrigine();
        sf::RectangleShape shape(sf::Vector2f(c*scale, c*scale));
        shape.setFillColor(sf::Color::Transparent);
        shape.setOutlineColor(sf::Color::Blue);
        shape.setOutlineThickness(2);
        shape.setPosition(sf::Vector2f(
            originX + p.GetX()*scale,
            originY - p.GetY()*scale - c*scale
        ));
        window.draw(shape);
        return;
    }

    // TRIANGLE
    if (auto t = dynamic_cast<const Triangle*>(f)) {
        sf::ConvexShape tri;
        tri.setPointCount(3);
        tri.setPoint(0, sf::Vector2f(
            originX + t->GetA().GetX()*scale,
            originY - t->GetA().GetY()*scale
        ));
        tri.setPoint(1, sf::Vector2f(
            originX + t->GetB().GetX()*scale,
            originY - t->GetB().GetY()*scale
        ));
        tri.setPoint(2, sf::Vector2f(
            originX + t->GetC().GetX()*scale,
            originY - t->GetC().GetY()*scale
        ));
        tri.setFillColor(sf::Color::Transparent);
        tri.setOutlineColor(sf::Color::Yellow);
        tri.setOutlineThickness(2);
        window.draw(tri);
        return;
    }
   
    // POLYGONE
    if (auto p = dynamic_cast<const Polygone*>(f)) {
        const auto& points = p->GetPoints();
        if (points.size() >= 3) {
            sf::ConvexShape polygon;
            polygon.setPointCount(points.size());
            
            for (size_t i = 0; i < points.size(); ++i) {
                polygon.setPoint(i, sf::Vector2f(
                    originX + points[i].GetX() * scale,
                    originY - points[i].GetY() * scale
                ));
            }
            
            polygon.setFillColor(sf::Color::Transparent);
            polygon.setOutlineColor(sf::Color::Magenta);
            polygon.setOutlineThickness(2);
            window.draw(polygon);
        }
        return;
    }
}

void DrawingWindow::Run() {
    while (window.isOpen()) {
        while (auto event = window.pollEvent()) {
            if (event->is<sf::Event::Closed>())
                window.close();
        }

        window.clear(sf::Color::Black);
        drawAxes();
        for (auto s : shapes) 
            drawShape(s);
        window.display();
    }
}
