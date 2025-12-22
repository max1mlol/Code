#include<stdio.h>
#include<string.h>
int main(){
    int i;
    char s[] = "hello";
    char s2[20] = "MUIS-iinhaan ";
    for(i=0; i<20; i++){
        s2[i] = s[i];
    }
    printf("%s", s2);
    return 0;
}