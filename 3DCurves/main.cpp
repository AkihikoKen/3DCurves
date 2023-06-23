#include "curves.h"

#include <iostream>
#include <vector>
#include <algorithm>

double const PI = 3.1415926535;

int main() {
    std::vector<Curve*> curves;

    //создаем кривые
    Circle circle1(5.0);
    Circle circle2(3.0);
    Ellipse ellipse(3.0, 2.0);
    Spiral spiral(4.0, 0.5);

    //добавляем в контейнер
    curves.push_back(&circle1);
    curves.push_back(&circle2);
    curves.push_back(&ellipse);
    curves.push_back(&spiral);

    //условие задачи t = PI/4
    double t = PI / 4;

    std::cout << "Coordinates and Derivatives at t = PI/4:\n";
    for (Curve* curve : curves) {
        Vector3D coordinate = curve->getCoordinate(t);
        Vector3D derivative = curve->getDerivative(t);

        std::cout << "Curve name: ";
        if (dynamic_cast<Circle*>(curve)) {
            std::cout << "Circle\n";
        }
        else if (dynamic_cast<Ellipse*>(curve)) {
            std::cout << "Ellipse\n";
        }
        else if (dynamic_cast<Spiral*>(curve)) {
            std::cout << "Spiral\n";
        }

        std::cout << "Coordinate: (" << coordinate.x << ", " << coordinate.y << ", " << coordinate.z << ")\n";
        std::cout << "Derivative: (" << derivative.x << ", " << derivative.y << ", " << derivative.z << ")\n";
        std::cout << std::endl;
    }

    //второй контейнер, где только окружности должны быть
    std::vector<Circle*> circlesOnly;

    for (Curve* curve : curves) {
        if (Circle* circle = dynamic_cast<Circle*>(curve)) {
            circlesOnly.push_back(circle);
        }
    }

    //сортируем второй контейнер
    std::sort(circlesOnly.begin(), circlesOnly.end(), [](Circle* a, Circle* b) {
        return a->getCoordinate(0.0).x < b->getCoordinate(0.0).x;
        });

    //выводим отсортированный второй контейнер
    std::cout << "Sorted Circles:\n";
    for (Circle* circle : circlesOnly) {
        std::cout << "Radius: " << circle->getCoordinate(0.0).x << std::endl;
    }

    //сумма радиусов всех окружностей из второго контейнера
    double totalRadius = 0.0;
    for (Circle* circle : circlesOnly) {
        totalRadius += circle->getCoordinate(0.0).x;
    }

    std::cout << "Total Radius: " << totalRadius << std::endl;

    return 0;
}