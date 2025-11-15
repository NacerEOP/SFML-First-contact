#include <SFML/Graphics.hpp>
#include <cmath>
#include <vector>

class Point3D {
private:
    double x, y, z;
public:
    Point3D(double x = 0, double y = 0, double z = 0) : x(x), y(y), z(z) {}
    double GetX() const { return x; }
    double GetY() const { return y; }
    double GetZ() const { return z; }
};

class Cube {
private:
    Point3D center;
    float size;
    std::vector<Point3D> vertices;
    float rotationX, rotationY, rotationZ;

public:
    Cube(Point3D center = {0,0,0}, float size = 2.0f) 
        : center(center), size(size), rotationX(0), rotationY(0), rotationZ(0) {
        
        // Define all 8 vertices of a proper 3D cube
        float half = size / 2.0f;
        vertices = {
            // Front face
            Point3D(-half, -half, -half),
            Point3D( half, -half, -half),
            Point3D( half,  half, -half),
            Point3D(-half,  half, -half),
            // Back face
            Point3D(-half, -half,  half),
            Point3D( half, -half,  half),
            Point3D( half,  half,  half),
            Point3D(-half,  half,  half)
        };
    }
    
    void Update(float deltaTime) {
        rotationX += 1.0f * deltaTime;
        rotationY += 1.5f * deltaTime;
        rotationZ += 0.5f * deltaTime;
    }

    void Draw(sf::RenderWindow& window, float originX, float originY, float scale) const {
        std::vector<sf::Vector2f> projectedVertices;
        
        // Project 3D points to 2D screen with rotation
        for (const auto& vertex : vertices) {
            float x = vertex.GetX();
            float y = vertex.GetY();
            float z = vertex.GetZ();
            
            // Apply 3D rotations
            // X rotation
            float y1 = y * cos(rotationX) - z * sin(rotationX);
            float z1 = y * sin(rotationX) + z * cos(rotationX);
            
            // Y rotation
            float x2 = x * cos(rotationY) - z1 * sin(rotationY);
            float z2 = x * sin(rotationY) + z1 * cos(rotationY);
            
            // Z rotation
            float x3 = x2 * cos(rotationZ) - y1 * sin(rotationZ);
            float y3 = x2 * sin(rotationZ) + y1 * cos(rotationZ);
            
            // Simple perspective projection
            float distance = 5.0f;
            float f = distance / (distance + z2);
            
            // Convert to screen coordinates
            projectedVertices.push_back(sf::Vector2f(
                originX + (center.GetX() + x3 * f) * scale,
                originY - (center.GetY() + y3 * f) * scale
            ));
        }
        
        // Define edges for a proper cube (12 edges)
        int edges[12][2] = {
            // Front face
            {0,1}, {1,2}, {2,3}, {3,0},
            // Back face
            {4,5}, {5,6}, {6,7}, {7,4},
            // Connecting edges
            {0,4}, {1,5}, {2,6}, {3,7}
        };
        
        // Draw all edges
        for (int i = 0; i < 12; i++) {
            sf::Vertex line[2];
            line[0].position = projectedVertices[edges[i][0]];
            line[0].color = sf::Color::Cyan;
            line[1].position = projectedVertices[edges[i][1]];
            line[1].color = sf::Color::Cyan;
            window.draw(line, 2, sf::PrimitiveType::Lines);
        }
    }
};

int main() {
    sf::RenderWindow window(sf::VideoMode({800, 600}), "3D Rotating Cube");
    Cube cube({0, 0, 0}, 2.5f);  // Smaller size for better view
    sf::Clock clock;
    
    while (window.isOpen()) {
        for (auto event = window.pollEvent(); event.has_value(); event = window.pollEvent()) {
            if (event->is<sf::Event::Closed>()) {
                window.close();
            }
        }
        
        float deltaTime = clock.restart().asSeconds();
        cube.Update(deltaTime);
        
        window.clear(sf::Color::Black);
        
        // Draw coordinate axes
        sf::Vertex xAxis[2];
        xAxis[0].position = sf::Vector2f(0, 300);
        xAxis[0].color = sf::Color::White;
        xAxis[1].position = sf::Vector2f(800, 300);
        xAxis[1].color = sf::Color::White;
        
        sf::Vertex yAxis[2];
        yAxis[0].position = sf::Vector2f(400, 0);
        yAxis[0].color = sf::Color::White;
        yAxis[1].position = sf::Vector2f(400, 600);
        yAxis[1].color = sf::Color::White;
        
        //window.draw(xAxis, 2, sf::PrimitiveType::Lines);
       // window.draw(yAxis, 2, sf::PrimitiveType::Lines);
        
        // Draw the rotating cube
        cube.Draw(window, 400, 300, 100.0f);
        
        window.display();
    }

    return 0;
}