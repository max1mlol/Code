#include<stdio.h>
#include<string.h>
int main(){
    int i, max, count, n, m, start, end, k;
    char a[500];
    scanf("%[^\n]", a);
    max = 0;
    int len = strlen(a);
    for(i=0;i<len;i++){
        count = 0;
        int j = i;
        n=j;
        while(j < len && a[j] != ' '){
            if(a[j] == 'a' || a[j] == 'e'  || a[j] == 'i' || a[j] == 'o' || a[j] == 'u' || a[j] == 'A' || a[j] == 'E'  || a[j] == 'I' || a[j] == 'O' || a[j] == 'U'){
                count++;
                
            }
            j++;
        }
        m=j;
        if(count > max){
            max = count;
            i = j;
            start = n;
            end = m;
        }
    }
    for(k=start;k<end;k++){
        printf("%c", a[k]);
    }
    return 0;
}