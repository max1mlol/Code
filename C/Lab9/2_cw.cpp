#include<stdio.h>
#include<math.h>
struct Point {
    int x, y;
};
double distance (struct Point s1, struct Point s2);
double distance(struct Point s1, struct Point s2){
    return sqrt((s2.x-s1.x)*(s2.x-s1.x)+(s2.y-s1.y)*(s2.y-s1.y));
}
int main(){
    struct Point s1;
    printf("Point A coordinates: ");
    scanf("%d %d", &s1.x, &s1.y);
    
    struct Point s2;
    printf("Point B coordinates: ");
    scanf("%d %d", &s2.x, &s2.y);
    
    double d = distance(s1, s2);
    printf("A, B distance: %f", d);
    return 0;
}
