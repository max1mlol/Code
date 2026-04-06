#include<iostream>
using namespace std;
class Student{
    public:
        string name;
    protected:
        int age;
    private:
        int id;
};

class A: public Student{
    public:
    void test(){
        name = "Munkh";
        age = 19;
    }
};

class B: protected Student{
    public:
    void test(){
        name = "Jargal";
        age = 20;
    }
};

class C: private Student{
    public:
    void test(){
        name = "Bat";
        age = 21;
    }
};

int main(){
    A a;
    a.name = "Munkh";
    
    B b;
    // b.name = "Jargal";

    C c;
    // c.name = "Bat";

    return 0;
}