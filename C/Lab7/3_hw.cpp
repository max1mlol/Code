#include<stdio.h>
#include<string.h>
int main(){
    int start, end;
    char str[200], str2[20];
    
    scanf("%[^\n]", str);
    scanf("%s", str2);
    char* ch = strstr(str, str2);  //str murd str2 mur bga esehiig shalgana. baival tuunii haygiig esvel NULL butsaana.
    if(ch != NULL){
        start = ch - str; 
        end = start + strlen(str2)-1;
        printf("%d ", start);
        printf("%d ", end);
    }
    else{
        printf("-1");
    }
    return 0;
}