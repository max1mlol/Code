#include<stdio.h>
#include<string.h>
int main(){
    char a[100], b[100];
    int i, j, count=0;
    gets(a);
    gets(b);
    for(i=0,j=0;i<strlen(a),j<strlen(b);i++,j++){
        if(a[i] == b[j]){
            count++;
        }
    }
    if(count == strlen(a)){
        printf("adilhan ug");
    }
    else{
        printf("adilhan ug bish");
    }
    return 0;
}