#include<stdio.h>
int main(){
    int n, i, sum=0;
    scanf("%d", &n);
    int A[n];
    for(i=0;i<n;i++){
        scanf("%d", &A[i]);
    }
    for(i=1;i<n;i++){
        if(A[i]>A[i-1]){
            sum += 1;
        }
    }
    for(i=1;i<n;i++){
        if(A[i]<A[i-1]){
            sum -= 1;
        }
    }
    if(sum==(n-1)){
        printf("Ascending");
    }
    else if(sum==((n-1)*-1)){
        printf("Descending");
    }
    else{
        printf("Unordered");
    }
    return 0;
}