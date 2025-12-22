#include<stdio.h>
int main(){
    int a, b, i;
    scanf("%d", &a);
    scanf("%d", &b);
    if(a>b){
        i=a;
    }
    else{
        i=b;
    }
    for(i;i>0;i--){
        if(a%i==0){
            if(b%i==0){
                printf("%d", i);
                i=0;
            }
        }
    }
    return 0;
}