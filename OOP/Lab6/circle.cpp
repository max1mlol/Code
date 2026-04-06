#include <iostream>
#include <string>
#include <cmath>
using namespace std;

const double PI = 3.14159265358979323846;

//Эх класс Shape
class Shape {
protected:
    string name;
public:
    Shape(string n = "Helber") : name(n) {}
    string getName() const { return name; }
    virtual void showInfo() const {
        cout << "Helber: " << name << endl;
    }
};

// 2Dshape 
    class TwoDshape : public Shape {
protected:
string color;
public:
TwoDshape(string n, string c) : Shape(n), color(c) {}
    virtual double area() const = 0;
    virtual double perimeter() const = 0;
    void showInfo() const override {
    Shape::showInfo();
    cout << "Ungu: " << color << endl;
    }
};

class Circle : public TwoDshape {
    private:
    double ox, oy;      //Тойргийн төвийн координатууд
    double radius;       // Тойргийн тал
public:
    Circle(string n, string c, double x, double y, double r)
    : TwoDshape(n, c), ox(x), oy(y), radius(r) {
    }
    double area() const override {
        return PI * radius * radius; // Тойргийн талбай
    }
    double perimeter() const override {
        return 2 * PI * radius; // Тойргийн периметр
    }   

void showInfo() const override {
    TwoDshape::showInfo();
    cout << "Turul: Toirog" << endl;
    cout << "Toirgiin tuv: (" << ox << ", " << oy << ")" << endl;
    cout << "Radius: " << radius << endl;
    cout << "Talbai: " << area() << endl;
    cout << "Perimeter: " << perimeter() << endl;
}
};

int main() {
    Circle c("Circle", "Black", 0.0, 0.0, 1.0); // Тойргийн нэр, өнгө, төвийн координатууд, радиус
    c.showInfo();
    return 0;
}