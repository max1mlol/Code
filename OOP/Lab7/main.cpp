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
// Цэгийн бүтэц
struct Point {
    double x, y;
};
class Square : public TwoDshape {
private:
    Point vertices[4];
    double side;

public:
    // leftTop = зүүн дээд орой
    Square(string n, double x, double y, double s) : TwoDshape(n, "White"){
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

void showInfo() const override {
    cout << "Square" << endl;
    cout << "Name: " << name << endl;
    cout << "Side: " << side << endl;
    cout << "Vertices:" << endl;
    for (int i = 0; i < 4; i++) {
        cout << "V" << i + 1 << ": (" << vertices[i].x << ", " << vertices[i].y << ")" << endl;
    }
    cout << "Area: " << area() << endl;
    cout << "Perimeter: " << perimeter() << endl;
    cout << "----------------------------------------------------" << endl;
}
};
void swap(TwoDshape*& a, TwoDshape*& b){
    TwoDshape* temp = a;
    a = b;
    b = temp;
}
void sort(TwoDshape* shapes[], int n) {
    for(int i = 0; i < n-1; i++) {
        for(int j = 0; j < n-i-1; j++) {
            if(shapes[j]->area() < shapes[j+1]->area()) {
                swap(shapes[j], shapes[j+1]);
            }
        }
    }
}
int main() {
    TwoDshape* Shapes[3];
    Shapes[0] = new triangle("Triangle", "Red", 0.0, 0.0, 4.0);
    Shapes[1] = new Circle("Circle", "Black", 0.0, 0.0, 1.0);
    Shapes[2] = new Square("Square", 0, 10, 4);
    cout << "===EREMBELEHIIN UMNU===" << endl;
    for(int i=0; i<3; i++){
        Shapes[i]->showInfo();
    }
    sort(Shapes, 3);
    cout << "===EREMBELSNII DARAA===" << endl;
    for(int i=0; i<3; i++){
        Shapes[i]->showInfo();
    }

    for(int i=0; i<3; i++){
        delete Shapes[i];
    }
    return 0;
}