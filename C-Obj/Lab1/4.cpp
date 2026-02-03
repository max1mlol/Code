#include<iostream>
using namespace std;
int main(){
    int n, i;
    double sum=0, avg;
    cin>>n;
    for(i=1;i<n+1;i++){
        sum=sum+i;  
    }
    avg = sum/n;
    cout<<"sum: "<<sum<<" avg: "<<avg<<endl;
}