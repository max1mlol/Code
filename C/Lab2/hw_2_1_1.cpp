#include<stdio.h>
int main(){
    int a, a1, b=0, c;
    scanf("%d", &a);
    a1 = a;
    while(a/10>0){
        b = b*10 + a%10;
        a = (a-a%10)/10;
    }
    b = b*10 + a;
    c = a1 - b;
    switch(c){
        case 0: printf("1");break;
        default: printf("0");
    }
    return 0;
}