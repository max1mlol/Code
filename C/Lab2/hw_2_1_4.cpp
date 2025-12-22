#include<stdio.h>
#include<math.h>
int main(){
    int a, a1, i, j, k, max=0, temp, x;
    printf("10 orontoi too oruul: ");
    scanf("%d", &a);
    a1 = a;
    for(i=1;i<=10;i++){
        j = (a1/(int)pow(10,i-1))%10;
        k = 0;
        temp = a;
        while(temp>0){
            if(j == temp%10){
                k = k+1;
            }
            temp = (temp-temp%10)/10;
        }
        a = a1/(int)pow(10,i);
        if(k>max){
            max = k;
            x = j;
        }
    }
    printf("%d", x);
    return 0;
}