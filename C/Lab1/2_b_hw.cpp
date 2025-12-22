#include <stdio.h>
#include <math.h>
int main() {
    float a, b, angle, c;
    scanf("%f %f %f", &a, &b, &angle);
    c = sqrt(b*b + a*a - 2*a*b*cos(angle * M_PI / 180)); // angle = 30, 45, ...
    printf("%f", c);
    return 0;
}
