#include<iostream>
using namespace std;
int main(){
    int n, i;
    double sum=0, avg;
    cout<<"Heden too oruulah aa bichne uu: ";
    cin>>n;
    int A[n];
    cout<<"Toonuudaa oruulna uu: ";
    for(i=0;i<n;i++){
        cin>>A[i];
    }
    for(i=0;i<n;i++){
        sum += A[i];
    }
    avg = sum/n;
    cout<<"Oruulsan toonuudiin dundaj: "<<avg<<endl;
}