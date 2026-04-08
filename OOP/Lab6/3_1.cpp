#include <iostream>
using namespace std;

/*
1.  Нэг-нэг буюу дан удамшил (SINGLE INHERITANCE)
   Нэг эцэг -> нэг хүүхэд
*/
class Animal {
public:
    void eat() {
        cout << "Amitan hool idej baina" << endl;
    }
};

class Dog : public Animal {   // Ганц удамшил
public:
    void bark() {
        cout << "nohoi hutsaj baina" << endl;
    }
};


/*
2. Олон түвшинт удамшил (MULTILEVEL)
   Өвөг -> Эцэг -> Хүүхэд
*/
class LivingThing {
public:
    void breathe() {
        cout << "Amьtan amisgalj baina" << endl;
    }
};

class Mammal : public LivingThing {   // 2-р түвшин
public:
    void walk() {
        cout << "Huhtun amitad alhaj baina" << endl;
    }
};

class Cat : public Mammal {   // 3-р түвшин 
public:
    void meow() {
        cout << "Muur meow hiij baina" << endl;
    }
};


/*
3. Шаталсан удамшил (HIERARCHICAL)
   Нэг эцэг -> олон хүүхэд
*/
class Person {
public:
    void introduce() {
        cout << "Bi hun baina" << endl;
    }
};

class Student : public Person {   // Салбарласан удамшил
public:
    void study() {
        cout << "Oyutan suraltsaj baina" << endl;
    }
};

class Teacher : public Person {   // Салбарласан удамшил
public:
    void teach() {
        cout << "Bagsh zaaj baina" << endl;
    }
};


/*
4. Олон-нэг буюу нийлмэл удамшил (MULTIPLE INHERITANCE)
   Нэг хүүхэд -> олон эцэг
*/
class Father {
public:
    void strong() {
        cout << "Aav huchtei" << endl;
    }
};

class Mother {
public:
    void kind() {
        cout << "Eej saihan setgeltei" << endl;
    }
};

class Child : public Father, public Mother {   // Олон удамшил
public:
    void play() {
        cout << "Huuhed togloj baina" << endl;
    }
};


/*
5. Холимог удамшил (HYBRID)
   Олон төрлийн удамшил нийлсэн

        Device
        /   \
     Phone  Camera
        \   /
     Smartphone

   Энэ нь diamond бүтэц.
   virtual ашиглаж зөрчлийг шийдсэн.
*/
class Device {
public:
    void powerOn() {
        cout << "Device aslaa" << endl;
    }
};

class Phone : virtual public Device {   // Hybrid зүүн тал
public:
    void call() {
        cout << "Phone zalgaj baina" << endl;
    }
};

class Camera : virtual public Device {   // Hybrid баруун тал
public:
    void takePhoto() {
        cout << "Camera zurag avch baina" << endl;
    }
};

class Smartphone : public Phone, public Camera {   // Hybrid удамшил
public:
    void useApps() {
        cout << "Smartphone app ajilluulj baina." << endl;
    }
};


int main() {
    cout << "1. Dan udamshil" << endl;
    Dog d;
    d.eat();     // Animal-аас өвлөсөн
    d.bark();    // өөрийн функц

    cout << "\n2. Olon tuvshint udamshil" << endl;
    Cat c;
    c.breathe(); // LivingThing-аас
    c.walk();    // Mammal-аас
    c.meow();    // өөрийн

    cout << "\n3. Shatalsan udamshil" << endl;
    Student s;
    Teacher t;
    s.introduce(); // Person-аас
    s.study();
    t.introduce(); // Person-аас
    t.teach();

    cout << "\n4. Niilmel udamshil" << endl;
    Child ch;
    ch.strong(); // Father-аас
    ch.kind();   // Mother-аас
    ch.play();   // өөрийн

    cout << "\n5. Holimog udamshil" << endl;
    Smartphone sp;
    sp.powerOn();   // Device-аас
    sp.call();      // Phone-аас
    sp.takePhoto(); // Camera-аас
    sp.useApps();   // өөрийн

    return 0;
}