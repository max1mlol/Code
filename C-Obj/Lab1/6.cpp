#include<iostream>
using namespace std;
int main(){
    int n, i, j, temp;
    cout<<"Heden too oruulah aa bichne uu: ";
    cin>>n;
    int A[n];
    cout<<"Toonuudaa oruulna uu: ";
    for(i=0;i<n;i++){
        cin>>A[i];
    }
    for(i=0;i<n;i++){
        for(j=i+1;j<n;j++){
            if(A[i]>A[j]){
                temp = A[j];
                A[j] = A[i];
                A[i] = temp;
            }
        }
    }
    cout<<"min: "<<A[0]<<" max: "<<A[n-1]<<endl;
}