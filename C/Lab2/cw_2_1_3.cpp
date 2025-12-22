#include<stdio.h>
int main(){
    int a, b, c;
    scanf("%d", &a);
    scanf("%d", &b);
    scanf("%d", &c);
    a<b && a<c && b<c && printf("ih: %d, baga: %d, dund: %d", c, a, b);
    a<b && a<c && b>c && printf("ih: %d, baga: %d, dund: %d", b, a, c);
    b<c && b<a && a<c && printf("ih: %d, baga: %d, dund: %d", c, b, a);
    b<c && b<a && a>c && printf("ih: %d, baga: %d, dund: %d", a, b, c);
    c<a && c<b && a<b && printf("ih: %d, baga: %d, dund: %d", b, c, a);
    c<a && c<b && a>b && printf("ih: %d, baga: %d, dund: %d", a, c, b);
    return 0;
}