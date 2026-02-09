#include<iostream>
using namespace std;
int main(){
    int a, b, c;
    cout<<"3 too oruulna uu: ";
    cin>>a>>b>>c;
    cout<<"3 toonii hamgiin ih ni: ";
    if(a>b){
        if(a>c){
            cout<<a<<endl;
        }
        else{
            cout<<c<<endl;
        }
    }
    else{
        if(b>c){
            cout<<b<<endl;
        }
        else{
            cout<<c<<endl;
        }
    }
    return 0;
}