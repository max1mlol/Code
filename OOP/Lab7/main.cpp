#include <iostream>
#include <string>
#include <math.h>
using namespace std;

// Эх класс Shape
class Shape {
protected:
    string name;
    static int objectCount; // Бүх объектийг тоолох статик хувьсагч

public:
    Shape(string n = "Helber") : name(n) {
        objectCount++; // Байгуулагч дотор тоолуурыг нэмэгдүүлэх
    }

    virtual ~Shape() {
        objectCount--; // Устгагч дотор тоолуурыг хасах
    }

    string getName() const { return this->name; } // this ашиглах

    // Static getter функц
    static int getObjectCount() {
        return objectCount;
    }

    // Static setter функц
    static void resetObjectCount() {
        objectCount = 0;
    }

    virtual void showInfo() const {
        cout << "Helber: " << this->name << endl; // this ашиглах
    }
};

// Static хувьсагчийг анхны утгаар эхлүүлэх
int Shape::objectCount = 0;

// 2D дүрсийн класс
class TwoDshape : public Shape {
protected:
    string color;

public:
    TwoDshape(string n, string c) : Shape(n), color(c) {}

    // Жинхэнэ хийсвэр функцүүд
    virtual double area() const = 0;
    virtual double perimeter() const = 0;

    void showInfo() const override {
        Shape::showInfo();
        cout << "Ungu: " << this->color << endl; // this ашиглах
    }

    string getColor() const { return this->color; } // this ашиглах
};

// Гурвалжны класс
class triangle : public TwoDshape {
private:
    double tx, ty;
    double bx1, by1;
    double bx2, by2;
    double side;

public:
    triangle(string n, string c, double topX, double topY, double s)
        : TwoDshape(n, c), tx(topX), ty(topY), side(s) {
        double h = (sqrt(3.0) / 2.0) * s;
        this->bx1 = topX - s / 2.0; // this ашиглах
        this->by1 = topY - h;
        this->bx2 = topX + s / 2.0;
        this->by2 = topY - h;
    }

    double area() const override {
        return (sqrt(3.0) / 4.0) * this->side * this->side; // this ашиглах
    }

    double perimeter() const override {
        return 3 * this->side; // this ашиглах
    }

    void showInfo() const override {
        TwoDshape::showInfo();
        cout << "Talbai: " << this->area() << endl;
        cout << "Perimeter: " << this->perimeter() << endl;
        cout << "----------------------------------------------------" << endl;
    }
};

// Тойргийн класс
class Circle : public TwoDshape {
private:
    double ox, oy;
    double radius;

public:
    Circle(string n, string c, double x, double y, double r)
        : TwoDshape(n, c), ox(x), oy(y), radius(r) {}

    double area() const override {
        return M_PI * this->radius * this->radius; // this ашиглах
    }

    double perimeter() const override {
        return 2 * M_PI * this->radius; // this ашиглах
    }

    void showInfo() const override {
        TwoDshape::showInfo();
        cout << "Talbai: " << this->area() << endl;
        cout << "Perimeter: " << this->perimeter() << endl;
        cout << "----------------------------------------------------" << endl;
    }
};

// Цэгийн бүтэц
struct Point {
    double x, y;
};

// Квадратын класс
class Square : public TwoDshape {
private:
    Point vertices[4];
    double side;

public:
    Square(string n, double x, double y, double s) : TwoDshape(n, "White") {
        this->side = s; // this ашиглах
        this->vertices[0] = {x, y};
        this->vertices[1] = {x + this->side, y};
        this->vertices[2] = {x + this->side, y - this->side};
        this->vertices[3] = {x, y - this->side};
    }

    double area() const override {
        return this->side * this->side; // this ашиглах
    }

    double perimeter() const override {
        return 4 * this->side; // this ашиглах
    }

    void showInfo() const override {
        TwoDshape::showInfo();
        cout << "Talbai: " << this->area() << endl;
        cout << "Perimeter: " << this->perimeter() << endl;
        cout << "----------------------------------------------------" << endl;
    }
};

// Swap туслах функц
void swap(TwoDshape*& a, TwoDshape*& b) {
    TwoDshape* temp = a;
    a = b;
    b = temp;
}

// Талбайгаар эрэмбэлэх (Bubble Sort - буурах дарааллаар)
void sortByArea(TwoDshape* shapes[], int n) {
    for (int i = 0; i < n - 1; i++) {
        for (int j = 0; j < n - i - 1; j++) {
            if (shapes[j]->area() < shapes[j + 1]->area()) {
                swap(shapes[j], shapes[j + 1]);
            }
        }
    }
}

// Периметрээр эрэмбэлэх (Bubble Sort - буурах дарааллаар)
void sortByPerimeter(TwoDshape* shapes[], int n) {
    for (int i = 0; i < n - 1; i++) {
        for (int j = 0; j < n - i - 1; j++) {
            if (shapes[j]->perimeter() < shapes[j + 1]->perimeter()) {
                swap(shapes[j], shapes[j + 1]);
            }
        }
    }
}

int main() {
    const int N = 3;
    TwoDshape* Shapes[N];

    Shapes[0] = new triangle("Triangle", "Red", 0.0, 0.0, 4.0);
    Shapes[1] = new Circle("Circle", "Black", 0.0, 0.0, 1.0);
    Shapes[2] = new Square("Square", 0, 10, 4);

    // Статик хувьсагчаар нийт объектийн тоог хэвлэх
    cout << "Niit uussen object iin too: " << Shape::getObjectCount() << endl;
    cout << endl;

    cout << "============ EREMBELEHIIN UMNU ============" << endl;
    for (int i = 0; i < N; i++) {
        Shapes[i]->showInfo();
    }

    // Талбайгаар эрэмбэлэх
    sortByArea(Shapes, N);
    cout << "============ TALBAIGAAR EREMBELSENII DARAA ============" << endl;
    for (int i = 0; i < N; i++) {
        Shapes[i]->showInfo();
    }

    // Периметрээр эрэмбэлэх
    sortByPerimeter(Shapes, N);
    cout << "============ PERIMETREGEER EREMBELSENII DARAA ============" << endl;
    for (int i = 0; i < N; i++) {
        Shapes[i]->showInfo();
    }

    // Санах ой чөлөөлөх
    for (int i = 0; i < N; i++) {
        delete Shapes[i];
    }

    cout << "\nUstgasnii daraah object iin too: " << Shape::getObjectCount() << endl;

    return 0;
}