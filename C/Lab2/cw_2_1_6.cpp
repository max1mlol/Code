#include<stdio.h>
int main(){
    int a, b, c;
    scanf("%d %d %d", &a, &b, &c);
    if(a>=b && a>=c){
        printf("max: %d, ", a);
        if(b>=c){
            printf("min: %d", c);
        }
        else{
            printf("min: %d", b);
        }
    }
    else if(b>=a && b>=c){
        printf("max: %d, ", b);
        if(a>=c){
            printf("min: %d", c);
        }
        else{
            printf("min: %d", a);
        }
    }
    else if(c>=a && c>=b){
        printf("max: %d, ", c);
        if(a>=b){
            printf("min: %d", b);
        }
        else{
            printf("min: %d", a);
        }
    }
    else if(a>=b && a>=c){
        printf("max: %d, ", a);
        if(b>=c){
            printf("min: %d", c);
        }
        else{
            printf("min: %d", b);
        }
    }
}