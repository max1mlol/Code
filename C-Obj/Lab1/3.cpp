#include<iostream>
using namespace std;
int area(int n, int m);
int main(){
    int a, b, s;
    cout<<"Tegsh untsugtiin 2 taliig oruulna uu: ";
    cin>>a>>b;
    s = area(a, b);
    cout<<"Tegsh untsugtiin talbai: "<<s<<endl;
}
int area(int n, int m){
    int s = n*m;
    return s;
}