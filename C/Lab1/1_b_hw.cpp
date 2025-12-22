#include <stdio.h>
#include <math.h>
int main() {
    float a, b, c, x1, x2, d;
    scanf("%f %f %f", &a, &b, &c);
    d = b*b - 4*a*c;
    if(d == 0) {
        x1 = -b / (2*a);
        printf("%f", x1);
    }
    else {
        x1 = (-b + sqrt(d)) / (2*a);
        x2 = (-b - sqrt(d)) / (2*a);
        if (x1 < x2) {
            printf("%f %f", x1, x2);
        }
        else {
            printf("%f %f", x2, x1);
        }
    }
    return 0;
}
