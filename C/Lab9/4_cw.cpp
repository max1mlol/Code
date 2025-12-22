#include<stdio.h>
struct Rational {
    int d, n; // d/n gesen engiin butarhai
};
int simplify(int a, int b){
    if(b == 0){
        return a;
    }
    return simplify(b, a%b); // Euclid
}
typedef struct Rational Rational;
Rational add(Rational a, Rational b);
struct Rational add(struct Rational s1, struct Rational s2){
    struct Rational result;
    result.n = s1.n * s2.d + s2.n * s1.d;
    result.d = s1.d * s2.d;
    int g = simplify(result.n, result.d);
    result.n = result.n/g;
    result.d = result.d/g;
    return result;
}
Rational sub(Rational a, Rational b);
struct Rational sub(struct Rational s1, struct Rational s2){
    struct Rational result;
    result.n = s1.n * s2.d - s2.n * s1.d;
    result.d = s1.d * s2.d;
    int g = simplify(result.n, result.d);
    result.n = result.n/g;
    result.d = result.d/g;
    return result;
}
Rational mult(Rational a, Rational b);
struct Rational mult(struct Rational s1, struct Rational s2){
    struct Rational result;
    result.n = s1.n * s2.n;
    result.d = s1.d * s2.d;
    int g = simplify(result.n, result.d);
    result.n = result.n/g;
    result.d = result.d/g;
    return result;
}
Rational div(Rational a, Rational b);
struct Rational div(struct Rational s1, struct Rational s2){
    struct Rational result;
    result.n = s1.n * s2.d;
    result.d = s1.d * s2.n;
    int g = simplify(result.n, result.d);
    result.n = result.n/g;
    result.d = result.d/g;
    return result;
}
Rational print(Rational a, Rational b);
struct Rational print(struct Rational s1){
    struct Rational result;
    result.n = s1.n;
    result.d = s1.d;
    int g = simplify(result.n, result.d);
    result.n = s1.n/g;
    result.d = s1.d/g;
    return result;
}
int main(){
    struct Rational s1, s2;
    printf("Enter number A (n d): ");
    scanf("%d %d", &s1.n, &s1.d);
    printf("Enter number B (n d): ");
    scanf("%d %d", &s2.n, &s2.d);
    printf("A = %d/%d\n", s1.n, s1.d);
    printf("B = %d/%d\n", s2.n, s2.d);
    printf("A + B = %d/%d\n", add(s1, s2).n, add(s1, s2).d);
    printf("A - B = %d/%d\n", sub(s1, s2).n, sub(s1, s2).d);
    printf("A * B = %d/%d\n", mult(s1, s2).n, mult(s1, s2).d);
    printf("A / B = %d/%d\n", div(s1, s2).n, div(s1, s2).d);
    printf("Simplified: %d/%d", print(s1).n, print(s1).d);
    return 0;
}
