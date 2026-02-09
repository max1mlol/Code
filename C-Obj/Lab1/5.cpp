#include<iostream>
using namespace std;
int main(){
    int n, i, sum=0, mul=1;
    cout<<"Heden too oruulah aa bichne uu: ";
    cin>>n;
    cout<<"Toonuudaa oruulna uu: ";
    int A[n];
    for(i=0;i<n;i++){
        cin>>A[i];
        sum += A[i];
        mul *= A[i];
    }
    cout<<n<<" toonii niilber: "<<sum<<endl<<n<<" toonii urjver: "<<mul<<endl;
}