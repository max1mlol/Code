#include<stdio.h>
int main(){
    int n, i, sum=0;
    scanf("%d", &n);
    int A[n];
    for(i=0;i<n;i++){
        scanf("%d", &A[i]);
    }
    int x;
    scanf("%d", &x);
    for(i=0;i<n;i++){
        if(A[i]==x){
            printf("%d", i);
            sum +=1;
        }
    }
    if(sum==n){
        printf("-1");
    }
    return 0;
}