#include<stdio.h>
#include<math.h>
int main() {
    int a, b, c, d;
    float x;
    scanf("%d %d %d %d", &a, &b, &c, &d);
    x = sqrt((pow(a+b,2)) + d)/c;
    printf("%f", x);
    return 0;
}