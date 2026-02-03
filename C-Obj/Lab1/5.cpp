#include<iostream>
using namespace std;
int main(){
    int n, i, sum=0, mul=1;
    cin>>n;
    for(i=1;i<n+1;i++){
        sum=sum+i;
        mul=mul*i;
    }
    cout<<"sum: "<<sum<<" mul: "<<mul<<endl;

}