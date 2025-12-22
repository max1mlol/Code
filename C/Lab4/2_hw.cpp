#include<stdio.h>
int main(){
    int n, sum1, sum2=0, sum3=0, sum4=0, i, j;
    scanf("%d", &n);
    int A[n][n];
    for(i=0;i<n;i++){
        for(j=0;j<n;j++){
            scanf("%d", &A[i][j]);
        }
    }
    printf("Mur: ");
    for(i=0;i<n;i++){
        sum1=0;
        for(j=0;j<n;j++){
            sum1 += A[i][j];
        }
        printf("%d ", sum1);
    }
    printf("\nBagana: ");
    for(i=0;i<n;i++){
        sum2=0;
        for(j=0;j<n;j++){
            sum2 += A[j][i];
        }
        printf("%d ", sum2);
    }
    printf("\nDiagonal Left: ");
    for(i=0;i<n;i++){
        for(j=0;j<n;j++){
            if(i == j){
                sum3 += A[i][j];
            }
        }
    }
    printf("%d", sum3);
    printf("\nDiagonal Right:");
    for(i=0;i<n;i++){
        for(j=0;j<n;j++){
            if(i+j==n-1){
                sum4 += A[i][j];
            }
        }
    }
    printf("%d", sum4);
    return 0;
}