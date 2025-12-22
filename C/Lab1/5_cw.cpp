#include <stdio.h>
int main() {
    int a, b;
    float plus, minus, multiply, divide;
    int divide2;
    scanf("%d %d", &a, &b);
    plus = a + b;
    minus = a - b;
    multiply = a * b;
    divide = (float)a / b;
    divide2 = a % b;
    printf("%.0f %.0f %.0f %.2f %.d", plus, minus, multiply, divide, divide2);
    return 0;
}