#include "Figure.h"
#include <iostream>
#include <map>


sf::Color chooseColor() {
    std::cout << "Выберите цвет:\n";
    std::cout << "1. Белый\n";
    std::cout << "2. Красный\n";
    std::cout << "3. Зелёный\n";
    std::cout << "4. Синий\n";
    std::cout << "5. Жёлтый\n";
    std::cout << "6. Магента\n";
    std::cout << "7. Чёрный\n";

    int colorChoice;
    std::cin >> colorChoice;

    std::map<int, sf::Color> colorMap = {
        {1, sf::Color::White}, {2, sf::Color::Red}, {3, sf::Color::Green},
        {4, sf::Color::Blue},  {5, sf::Color::Yellow}, {6, sf::Color::Magenta}, {7, sf::Color::Black} };

    if (colorMap.count(colorChoice)) {
        return colorMap[colorChoice];
    }
    std::cout << "Неверный выбор, установлен белый цвет.\n";
    return sf::Color::White;
}

std::unique_ptr<Figure> createFigure() {
    std::cout << "Выберите тип фигуры:\n";
    std::cout << "1. Круг\n";
    std::cout << "2. Квадрат\n";
    std::cout << "3. Прямоугольник\n";
    std::cout << "4. Треугольник\n";
    std::cout << "5. Многоугольник\n";

    int choice;
    std::cin >> choice;

    sf::Color color = chooseColor();

    switch (choice) {
    case 1: {
        float radius, x, y;
        std::cout << "Введите радиус и координаты центра (x y): ";
        std::cin >> radius >> x >> y;
        return std::make_unique<Circle>(radius, sf::Vector2f(x, y), color);
    }
    case 2: {
        float side, x, y;
        std::cout << "Введите длину стороны и координаты (x y): ";
        std::cin >> side >> x >> y;
        return std::make_unique<Square>(side, sf::Vector2f(x, y), color);
    }
    case 3: {
        float width, height, x, y;
        std::cout << "Введите ширину, высоту и координаты (x y): ";
        std::cin >> width >> height >> x >> y;
        return std::make_unique<Rectangle>(width, height, sf::Vector2f(x, y), color);
    }
    case 4: {
        float x1, y1, x2, y2, x3, y3;
        std::cout << "Введите координаты трех вершин (x1 y1 x2 y2 x3 y3): ";
        std::cin >> x1 >> y1 >> x2 >> y2 >> x3 >> y3;
        return std::make_unique<Triangle>(sf::Vector2f(x1, y1), sf::Vector2f(x2, y2), sf::Vector2f(x3, y3), color);
    }
    case 5: {
        size_t numPoints;
        std::cout << "Введите количество вершин многоугольника: ";
        std::cin >> numPoints;

        std::vector<sf::Vector2f> points;
        for (size_t i = 0; i < numPoints; ++i) {
            float x, y;
            std::cout << "Введите координаты вершины " << i + 1 << " (x y): ";
            std::cin >> x >> y;
            points.emplace_back(x, y);
        }
        return std::make_unique<Polygon>(points, color);
    }
    default:
        std::cout << "Неверный выбор!\n";
        return nullptr;
    }
}

int main() {
    std::vector<std::unique_ptr<Figure>> figures;

    char choice;
    do {
        auto figure = createFigure();
        if (figure) {
            figures.push_back(std::move(figure));
        }
        std::cout << "Хотите добавить еще фигуру? (y/n): ";
        std::cin >> choice;
    } while (choice == 'y');

    sf::RenderWindow window(sf::VideoMode(800, 600), "Figures Viewer");

    while (window.isOpen()) {
        sf::Event event;
        while (window.pollEvent(event)) {
            if (event.type == sf::Event::Closed)
                window.close();
        }

        window.clear();

        for (const auto& figure : figures) {
            figure->draw(window);
        }

        window.display();
    }

    return 0;
}

