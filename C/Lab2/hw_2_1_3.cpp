#include<stdio.h>
int main(){
    int a;
    scanf("%d", &a);
    if(a%2==0){
        printf("Tegsh. ");
        if(a%20==0){
            printf("10, 4-t zereg huvaagdana");
        }
        else{
            printf("10, 4-t zereg huvaagdahgui");
        }
    }
    else{
        printf("Sondgoi. ");
        if(a%21==0){
            printf("3, 7-d zereg huvaagdana");
        }
        else{
            printf("3, 7-d zereg huvaagdahgui");
        }
    }
    return 0;
}