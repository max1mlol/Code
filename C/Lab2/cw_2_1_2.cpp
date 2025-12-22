#include<stdio.h>
int main(){
    int a=0, b=2, c=1;
    c < b && a < c && printf("bolj ");
    (a % 3 == 0 || c % 5 ==3) && printf("bna.\n");
    /*
        c<b, a<c=> a<c<b
        a%3==0 uyd: 0, 2, 1; 3, 5, 4; 3, 6, 5;...
        c%5==3 uyd: 2, 4, 3; 3, 12, 8;...
    */

}