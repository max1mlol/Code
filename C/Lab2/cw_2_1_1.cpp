#include<stdio.h>
int main(){
    int a, b, c, d;
    scanf("%d", &a);
    scanf("%d", &b);
    c=(a>b) * a + (a<=b) * b;
    d=(a<b) * a + (a>=b) * b;
    printf("%d %d", d, c);
    return 0;
}