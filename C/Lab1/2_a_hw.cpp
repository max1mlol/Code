#include <stdio.h>
#include <math.h>
int main() {
    float a, b, c, d, x;
    scanf("%f %f %f %f", &a, &b, &c, &d);
    x = (sqrt((a*a*a + (b/c)*(b/c)) + d) * d) / (d*d - (a*b)/c);
    printf("%f", x);
    return 0;
}
