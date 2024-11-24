#ifndef FIGURE_HPP
#define FIGURE_HPP

#include <SFML/Graphics.hpp>
#include <vector>
#include <memory>

class Figure {
protected:
    sf::Color color;
public:
    Figure(sf::Color c = sf::Color::White) : color(c) {}
    virtual void draw(sf::RenderWindow& window) const = 0;
    virtual void setColor(sf::Color c) { color = c; }
    virtual ~Figure() = default;
};

class Circle : public Figure {
    float radius;
    sf::Vector2f position;
public:
    Circle(float r, sf::Vector2f pos, sf::Color c = sf::Color::White);
    void draw(sf::RenderWindow& window) const override;
};


class Square : public Figure {
    float side;
    sf::Vector2f position;
public:
    Square(float s, sf::Vector2f pos, sf::Color c = sf::Color::White);
    void draw(sf::RenderWindow& window) const override;
};


class Rectangle : public Figure {
    float width, height;
    sf::Vector2f position;
public:
    Rectangle(float w, float h, sf::Vector2f pos, sf::Color c = sf::Color::White);
    void draw(sf::RenderWindow& window) const override;
};


class Triangle : public Figure {
    sf::Vector2f point1, point2, point3;
public:
    Triangle(sf::Vector2f p1, sf::Vector2f p2, sf::Vector2f p3, sf::Color c = sf::Color::White);
    void draw(sf::RenderWindow& window) const override;
};

class Polygon : public Figure {
    std::vector<sf::Vector2f> points;
public:
    Polygon(const std::vector<sf::Vector2f>& pts, sf::Color c = sf::Color::White);
    void draw(sf::RenderWindow& window) const override;
};

#endif // FIGURE_HPP