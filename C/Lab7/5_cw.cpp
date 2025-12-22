#include<stdio.h>
#include<string.h>
int main(){
    int i, j, k;
    char s[100],s2[100],s3[200];
    scanf("%s", s);
    scanf("%s", s2);
    for(i=0;i<strlen(s);i++){
        s3[i] = s[i];
    }
    for(j=0;j<strlen(s2);j++){
        s3[i+j] = s2[j];
    }
    printf("%s", s3);
    return 0;
}