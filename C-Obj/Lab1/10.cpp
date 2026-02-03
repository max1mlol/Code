#include<iostream>
using namespace std;
int main(){
    int n, i , count=0;
    cout<<"Too oruulna uu: ";
    cin>>n;
    for(i=1;i<=n;i++){
        if(n%i==0){
            count++;
        }
    }
    if(count==2){
        cout<<"Anhnii too mun"<<endl;
    }
    else{
        cout<<"Anhnii too bish"<<endl;
    }
}