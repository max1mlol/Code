#include <iostream>
#include <cmath>
#include <string>
using namespace std;

// Цэгийн бүтэц
struct Point {
    double x, y;
};

// 1. Эх класс: Shape

class Shape {
protected:
    string name;

public:
    Shape(string n = "") {
        name = n;
    }

    void setName(string n) {
        name = n;
    }

    string getName() const {
        return name;
    }
};

// 2. Дэд эх класс: 2DShape

class TwoDShape : public Shape {
public:
    TwoDShape(string n = "") : Shape(n) {}

    virtual double area() const = 0;
    virtual double perimeter() const = 0;
    virtual void display() const = 0;
};

class Square : public TwoDShape {
private:
    Point vertices[4];
    double side;

public:
    // leftTop = зүүн дээд орой
    Square(string n, double x, double y, double s) : TwoDShape(n) {
        side = s;

        // Зүүн дээд орой
        vertices[0] = {x, y};

        // Баруун дээд
        vertices[1] = {x + side, y};

        // Баруун доод
        vertices[2] = {x + side, y - side};

        // Зүүн доод
        vertices[3] = {x, y - side};
    }

    double area() const override {
        return side * side;
    }

    double perimeter() const override {
        return 4 * side;
    }

    void display() const override {
        cout << "Square" << endl;
        cout << "Name: " << name << endl;
        cout << "Side: " << side << endl;
        cout << "Vertices:" << endl;
        for (int i = 0; i < 4; i++) {
            cout << "V" << i + 1 << ": (" << vertices[i].x << ", " << vertices[i].y << ")" << endl;
        }
        cout << "Area: " << area() << endl;
        cout << "Perimeter: " << perimeter() << endl;
    }
};

int main() {
    double x, y, side;

    cout << "Zuun deed oroi (x y): ";
    cin >> x >> y;

    cout << "Taliin urt: ";
    cin >> side;

    Square sq("MySquare", x, y, side);

    sq.display();
    return 0;
}