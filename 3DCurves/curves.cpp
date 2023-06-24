#include "curves.h"

double const PI = 3.1415926535;

Vector3D::Vector3D(double x, double y, double z) : x(x), y(y), z(z) {}


Circle::Circle(double radius) : radius(radius) {}

Vector3D Circle::getCoordinate(double t) const {
    double x = radius * std::cos(t);
    double y = radius * std::sin(t);
    double z = 0.0;
    return Vector3D(x, y, z);
}

Vector3D Circle::getDerivative(double t) const {
    double dx = -radius * std::sin(t);
    double dy = radius * std::cos(t);
    double dz = 0.0;
    return Vector3D(dx, dy, dz);
}

Ellipse::Ellipse(double radiusX, double radiusY) : radiusX(radiusX), radiusY(radiusY) {}

Vector3D Ellipse::getCoordinate(double t) const {
    double x = radiusX * std::cos(t);
    double y = radiusY * std::sin(t);
    double z = 0.0;
    return Vector3D(x, y, z);
}

Vector3D Ellipse::getDerivative(double t) const {
    double dx = -radiusX * std::sin(t);
    double dy = radiusY * std::cos(t);
    double dz = 0.0;
    return Vector3D(dx, dy, dz);
}

Spiral::Spiral(double radius, double step) : radius(radius), step(step) {}

Vector3D Spiral::getCoordinate(double t) const {
    double x = radius * std::cos(t);
    double y = radius * std::sin(t);
    double z = step * t / (2 * PI);
    return Vector3D(x, y, z);
}

Vector3D Spiral::getDerivative(double t) const {
    double dx = -radius * std::sin(t);
    double dy = radius * std::cos(t);
    double dz = step / (2 * PI);
    return Vector3D(dx, dy, dz);
}