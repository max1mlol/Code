#include<stdio.h>
int main(){
    int n, m, i, j, k, sum;
    printf("A, B husnegtiin hemjeeg oruul: ");
    scanf("%d", &n);
    scanf("%d", &m);
    int A[n], B[m], C[n+m];
    printf("A husnegtiig duurge");
    for(i=0;i<n;i++){
        scanf("%d", A[i]);
        C[i]=A[i];
    }
    printf("B husnegtiig duurge");
    for(j=0;j<m;j++){
        scanf("%d", B[j]);
        sum = 0;
        for(i=0;i<n;i++){
            if(A[i]==B[j]){
                sum += 1;
            }
            if(sum == n){
                C[j+n] = B[j];
            }
        }
    }
    for(k=0;k<n+m;k++){
        printf("%d", C[k]);
    }
    return 0;
}