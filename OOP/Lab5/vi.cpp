#include<iostream>
using namespace std;
class Product{
    public:
    string name;
    int price;
    Product(string n, int p){
        name = n;
        price = p;
    }
};
int main(){
    Product* p = new Product("Keyboard", 100);
    cout << "Name, Price\n";
    cout << p -> name << ", " << p -> price << endl;
    delete p;
}