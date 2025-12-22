#include<stdio.h>
int main(){
    float a;
    scanf("%f", &a);
    a = (a*100)/35;
    printf("%.1f, ", a);
    if(a<60){
        printf("F");
    }
    else if(a<70){
        printf("D");
    }
    else if(a<80){
        printf("C");
    }
    else if(a<90){
        printf("B");
    }
    else{
        printf("A");
    }
    return 0;
}