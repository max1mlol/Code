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

class triangle : public TwoDshape {
    private:
    double tx, ty;      //Дээд оройн координатууд
    double bx1, by1;    // Зүүн доод оройн координатууд
    double bx2, by2;    // Баруун доод оройн координатууд
    double side;       // Гурвалжны тал
public:
    triangle(string n, string c, double topX, double topY, double s)
    : TwoDshape(n, c), tx(topX), ty(topY), side(s) {
    double h = (sqrt(3.0) / 2.0) * s; // Тэгш өнцөгт гурвалжны өндөр
    bx1 = topX - s / 2.0; // Зүүн доод оройн x координат
    by1 = topY - h; // Зүүн доод оройн y координат
    bx2 = topX + s / 2.0; // Баруун доод оройн x координат
    by2 = topY - h; // Баруун доод оройн y координат
    }
    double area() const override {
        return (sqrt(3.0) / 4.0) * side * side; // Тэгш өнцөгт гурвалжны талбай
    }
    double perimeter() const override {
        return 3 * side; // Тэгш өнцөгт гурвалжны периметр
    }

void showInfo() const override {
    TwoDshape::showInfo();
    cout << "Turul: Gurwaljin" << endl;
    cout << "Deed oroi: (" << tx << ", " << ty << ")" << endl;
    cout << "Dood oroinuud: (" << bx1 << ", " << by1 << ") and (" << bx2 << ", " << by2 << ")" << endl;
    cout << "Talbai: " << area() << endl;
    cout << "Perimeter: " << perimeter() << endl;
    cout << "----------------------------------------------------" << endl;
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
    cout << "----------------------------------------------------" << endl;

}
};
int main() {
    triangle t("Triangle", "Red", 0.0, 0.0, 4.0); // Гурвалжны нэр, өнгө, дээд оройн координатууд, талын урт
    t.showInfo();
    Circle c("Circle", "Black", 0.0, 0.0, 1.0); // Тойргийн нэр, өнгө, төвийн координатууд, радиус
    c.showInfo();
    return 0;
}