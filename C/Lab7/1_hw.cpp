#include<stdio.h>
#include<string.h>
int main(){
    int i, count = 0;
    char s[100];
    scanf("%[^\n]", s); //enter darah hurtelh buh characteriig scan hiine
    for(i=0;i<strlen(s);i++){
        if(s[i] == ' '){
            count++;
        }
    }
    if(count != 0){
        printf("%d", count+1);
    }
    else{
        printf("%d", count);
    }
    
    return 0;
}