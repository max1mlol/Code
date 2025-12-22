#include<stdio.h>
#include<string.h>
int main(){
    char a[100];
    gets(a);
    int i, count=0;
    count = 0;
    for(i=0;i<strlen(a);i++){
        if(a[i] == 'a' || a[i] == 'e'  || a[i] == 'i' || a[i] == 'o' || a[i] == 'u' || a[i] == 'A' || a[i] == 'E'  || a[i] == 'I' || a[i] == 'O' || a[i] == 'U'){
            count++;
        }
    }
   
    printf("%d\n", count);
    return 0;  
}