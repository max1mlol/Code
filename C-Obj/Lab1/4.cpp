#include<iostream>
using namespace std;
int main(){
    int n, i;
    float sum=0, avg;
    cout<<"Too oruulna uu: ";
    cin>>n;
    for(i=1;i<n+1;i++){
        sum=sum+i;  
    }
    avg = sum/n;
    cout<<n<<" hurtelh toonii niilber: "<<sum<<endl<<n<<" hurtelh toonii dundaj: "<<avg<<endl;
}