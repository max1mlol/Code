#include<stdio.h>
int main(){
    int m, k, n, x=1, i, j, h, y;
    printf("Orts: ");
    scanf("%d", &k);
    printf("Davhariin too: ");
    scanf("%d", &n);
    printf("Davhar dahi ailiin too: ");
    scanf("%d", &m);
    int A[k][n][m];
    for(i=0;i<k;i++){
        printf("\n%d-r orts: ", i+1);
        for(j=0;j<n;j++){
                for(h=0;h<m;h++){
                    A[i][j][h] = x;
                    x += 1;
                }
            }
            for(j=0;j<n;j++){
                for(h=0;h<m;h++){
                    printf("%d ", A[i][j][h]);
                }
            }
    }
    return 0;
}