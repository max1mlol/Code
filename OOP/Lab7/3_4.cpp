#include <iostream>
#include <math.h>
using namespace std;

class Shape {
public:
    virtual void area() {
        cout << "Area is not defined" << endl;
    }
};

class Circle : public Shape {
private:
    double radius;
public:
    Circle(double r) : radius(r) {}

    void area() override {
        cout << "Circle area: " << M_PI * radius * radius << endl;
    }
};

class Rectangle : public Shape {
private:
    double width, height;
public:
    Rectangle(double w, double h) : width(w), height(h) {}

    void area() override {
        cout << "Rectangle area: " << width * height << endl;
    }
};

class Triangle : public Shape {
private:
    double base, height;
public:
    Triangle(double b, double h) : base(b), height(h) {}

    void area() override {
        cout << "Triangle area: " << 0.5 * base * height << endl;
    }
};

int main() {
    Circle c(2);
    Rectangle r(2, 3);
    Triangle t(2, 3);

    c.area();
    r.area();
    t.area();
    return 0;
}