#include<iostream>
using namespace std;
int main(){
    int n, i , count=0;
    cout<<"Too oruulna uu: ";
    cin>>n;
    for(i=2;i<n;i++){
        if(n%i==0){
            cout<<"Anhnii too bish"<<endl;
            break;
        }
        else{
            count++;
        }
    }
    if(count==n-2){
        cout<<"Anhnii too mun"<<endl;
    }
}