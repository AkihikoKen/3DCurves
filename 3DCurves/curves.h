#ifndef CURVES_H
#define CURVES_H

#include <cmath>
#include <vector>
#include <algorithm>

class Vector3D {
public:
    double x;
    double y;
    double z;

    Vector3D(double x = 0.0, double y = 0.0, double z = 0.0);
};


class Curve {
public:
    virtual Vector3D getCoordinate(double t) const = 0;
    virtual Vector3D getDerivative(double t) const = 0;
};

class Circle : public Curve {
private:
    double radius;

public:
    Circle(double radius);

    Vector3D getCoordinate(double t) const override;
    Vector3D getDerivative(double t) const override;
};

class Ellipse : public Curve {
private:
    double radiusX;
    double radiusY;

public:
    Ellipse(double radiusX, double radiusY);

    Vector3D getCoordinate(double t) const override;
    Vector3D getDerivative(double t) const override;
};

class Spiral : public Curve {
private:
    double radius;
    double step;

public:
    Spiral(double radius, double step);

    Vector3D getCoordinate(double t) const override;
    Vector3D getDerivative(double t) const override;
};

#endif