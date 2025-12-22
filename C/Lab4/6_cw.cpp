#include<stdio.h>
int main(){
    int n, m, i, j;
    printf("Husnegtnii hemjee oruul: ");
    scanf("%d", &n);
    scanf("%d", &m);
    int A[n][m];
    printf("Husnegt duurge: ");
    for(i=0;i<n;i++){
        for(j=0;j<m;j++){
            scanf("%d", &A[i][j]);
        }
    }
    int x, sum=0;
    printf("Shalgah too oruul: ");
    scanf("%d", &x);
    for(i=0;i<n;i++){
        for(j=0;j<m;j++){
            if(A[i][j]==x){
                printf("Mur: %d, Bagana: %d", i, j);
            }
            else{
                sum +=1;
            }
        }
    }
    if(sum==n*m){
        printf("1,-1");
    }
    return 0;
}