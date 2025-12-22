#include<stdio.h>
#include<math.h>
struct Triangle {
    int a, b, c; //a, b, c, ni gurvaljnii 3 taliin urt
};
int main(){
    int p, s, x, y;
    struct Triangle s1;
    struct Triangle s2;
    scanf("%d", &s1.a);
    scanf("%d", &s1.b);
    scanf("%d", &s1.c);
    if(s1.a+s1.b<=s1.c || s1.a+s1.c<=s1.b || s1.b+s1.c<=s1.a){
        printf("This is not a triangle");
        return 0;
    }
    p = (s1.a+s1.b+s1.c)/2;
    s = sqrt(p*(p-s1.a)*(p-s1.b)*(p-s1.c));
    scanf("%d", &s2.a);
    scanf("%d", &s2.b);
    scanf("%d", &s2.c);
    if(s2.a+s2.b<=s2.c || s2.a+s2.c<=s2.b || s2.b+s2.c<=s2.a){
        printf("This is not a triangle");
        return 0;
    }
    x = (s2.a+s2.b+s2.c)/2;
    y = sqrt(x*(x-s2.a)*(x-s2.b)*(x-s2.c));
    if(s>y){
        printf("triangle 1 is bigger");
    }
    else{
        printf("triangle 2 is bigger");
    }
    return 0;
}