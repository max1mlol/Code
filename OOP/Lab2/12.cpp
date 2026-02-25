#include<iostream>
using namespace std;
void swap(int &x, int &y){
    int temp;
    temp = x;
    x = y;
    y = temp;
}
int main(){
    int a, b;
    cout<<"a toog oruulna uu: ";
    cin>>a;
    cout<<"b dahi toog oruulna uu: ";
    cin>>b;
    cout<<"Solihiin umnu a = "<<a<<", b = "<<b<<endl;
    swap(a, b);
    cout<<"Solisonii daraa a = "<<a<<", b = "<<b<<endl;

}