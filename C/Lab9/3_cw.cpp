#include<stdio.h>
#include<math.h>
struct Triangle {
    int a, b, c;
};
double find_area(struct Triangle s);
int main(){
    struct Triangle s1;
    printf("Triangle A side lengths: ");
    scanf("%d %d %d", &s1.a, &s1.b, &s1.c);

    struct Triangle s2;
    printf("Triangle B side lengths: ");
    scanf("%d %d %d", &s2.a, &s2.b, &s2.c);

    if(find_area(s1)>find_area(s2)){
        printf("Triangle A is bigger");
    }
    else if(find_area(s1)==find_area(s2)){
        printf("Triangle A and B are equal");
    }
    else{
        printf("Triangle B is bigger");
    }
    return 0;
}
double find_area(struct Triangle s){
    int p = (s.a+s.b+s.c)/2;
    int q = sqrt(p*(p-s.a)*(p-s.b)*(p-s.c));
    return q;
}
