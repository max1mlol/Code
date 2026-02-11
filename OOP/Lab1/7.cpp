#include<iostream>
using namespace std;
int main(){
    int n, i, count=0;
    cout<<"Heden too oruulah aa bichne uu: ";
    cin>>n;
    int A[n];
    cout<<"Toonuudaa oruulna uu: ";
    for(i=0;i<n;i++){
        cin>>A[i];
    }
    for(i=0;i<n;i++){
        if(A[i]%2==0){
            count++;
        }
    }

    cout<<"Niit "<<count<<" tegsh too baina"<<endl;
}