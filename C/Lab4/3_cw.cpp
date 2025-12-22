#include<stdio.h>
int main(){
    int n, m, i, j, k;
    scanf("%d", &n);
    scanf("%d", &m);
    int A[n], B[m], C[n+m];
    for(i=0;i<n;i++){
        scanf("%d", &A[i]);
        C[i]=A[i];
    }
    for(j=0;j<m;j++){
        scanf("%d", &B[j]);
        C[j+n]=B[j];
    }
    for(k=0;k<n+m;k++){
        printf("%d ", C[k]);
    }
    return 0;
}