#include<iostream>
using namespace std;
double average(double A[], int x);
int main(){
    int n, i;
    cout<<"Heden too oruulah aa bichne uu: ";
    cin>>n;
    double A[n], dundaj;
    cout<<"Toonuudaa oruulna uu: ";
    for(i=0;i<n;i++){
        cin>>A[i];
    }
    
    dundaj = average(A, n);
    cout<<"Oruulsan toonuudiin dundaj: "<<dundaj<<endl;
}
double average(double A[], int x){
    double sum = 0, avg;
    for(int i=0;i<x;i++){
        sum += A[i];
    }
    avg = sum/x;
    return avg;
}