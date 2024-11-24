#include "Figure.h"

Circle::Circle(float r, sf::Vector2f pos, sf::Color c) : Figure(c), radius(r), position(pos) {}
void Circle::draw(sf::RenderWindow& window) const {
    sf::CircleShape circle(radius);
    circle.setPosition(position);
    circle.setFillColor(color);
    window.draw(circle);
}

Square::Square(float s, sf::Vector2f pos, sf::Color c) : Figure(c), side(s), position(pos) {}
void Square::draw(sf::RenderWindow& window) const {
    sf::RectangleShape square(sf::Vector2f(side, side));
    square.setPosition(position);
    square.setFillColor(color);
    window.draw(square);
}

Rectangle::Rectangle(float w, float h, sf::Vector2f pos, sf::Color c) : Figure(c), width(w), height(h), position(pos) {}
void Rectangle::draw(sf::RenderWindow& window) const {
    sf::RectangleShape rectangle(sf::Vector2f(width, height));
    rectangle.setPosition(position);
    rectangle.setFillColor(color);
    window.draw(rectangle);
}

Triangle::Triangle(sf::Vector2f p1, sf::Vector2f p2, sf::Vector2f p3, sf::Color c) : Figure(c), point1(p1), point2(p2), point3(p3) {}
void Triangle::draw(sf::RenderWindow& window) const {
    sf::ConvexShape triangle;
    triangle.setPointCount(3);
    triangle.setPoint(0, point1);
    triangle.setPoint(1, point2);
    triangle.setPoint(2, point3);
    triangle.setFillColor(color);
    window.draw(triangle);
}

Polygon::Polygon(const std::vector<sf::Vector2f>& pts, sf::Color c) : Figure(c), points(pts) {}
void Polygon::draw(sf::RenderWindow& window) const {
    sf::ConvexShape polygon;
    polygon.setPointCount(points.size());
    for (size_t i = 0; i < points.size(); ++i) {
        polygon.setPoint(i, points[i]);
    }
    polygon.setFillColor(color);
    window.draw(polygon);
}
