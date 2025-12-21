#include <stdio.h>
#include <stdlib.h>

int* createArray(int n){
    return (int*)malloc(n * sizeof(int));
}

void read(int a[], int n){
    for(int i = 0; i < n; i++){
        printf("a[%d] = ", i);
        scanf("%d", &a[i]);
    }
}

void print(int a[], int n){
    for(int i = 0; i < n; i++)
        printf("%d ", a[i]);
    printf("\n");
}

void deleteArray(int *a){
    free(a);
}

int minA(int a[], int n){
    int min = a[0];
    for(int i = 1; i < n; i++)
        if(a[i] < min)
            min = a[i];
    return min;
}

int maxA(int a[], int n){
    int max = a[0];
    for(int i = 1; i < n; i++)
        if(a[i] > max)
            max = a[i];
    return max;
}

float average(int a[], int n){
    int sum = 0;
    for(int i = 0; i < n; i++)
        sum += a[i];
    return (float)sum / n;
}

int searchA(int a[], int n, int Svalue){
    for(int i = 0; i < n; i++)
        if(a[i] == Svalue)
            return i;
    return -1;
}

void sortA(int a[], int n){
    for(int i = 0; i < n - 1; i++)
        for(int j = i + 1; j < n; j++)
            if(a[i] > a[j]){
                int t = a[i];
                a[i] = a[j];
                a[j] = t;
            }
}
