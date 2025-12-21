#include<stdio.h>
// usuhuur erembeleh haritsuulah function
int compare_asc(/*implement*/const int *a, const int *b){
    // implement
    return *a - *b;
}

// buurahaar erembeleh haritsuulah function
int compare_desc(/*implement*/const int *a, const int *b){
    // implement
    return *b - *a;
}

//haritsuulah function ni zaagchaar ugugdsun erembeleh funcion
void sort_array(int *arr, int size, int (*compare)(const int *, const int*)) {
    // heregjuuleh
    for (int i=0;i<size-1;i++){
        for(int j=0;j<size-i-1;j++){
            if (compare(&arr[j], &arr[j+1]) > 0) {
                int temp = arr[j];
                arr[j] = arr[j+1];
                arr[j+1] = temp;
            }
        }
    }
}

//elementuudiig hevleh
void print_array(int *arr, int size) {
    for (int i=0; i < size; i++) {
        printf("%d ", arr[i]);
    }
    printf("\n");
}

int main() {
    int arr[] = {1, 3, 5, 7, 9, 8, 6, 4, 2, 0};
    int size = sizeof(arr) / sizeof(arr[0]);

    printf("Original array: ");
    print_array(arr, size);

    // usuhuur erembelj hevlej haruulah
    sort_array(arr, size, compare_asc);
    printf("Array sorted in ascending order: ");
    print_array(arr, size);

    // buurahaar erembelj hevlej haruulah
    sort_array(arr, size, compare_desc);
    printf("Array sorted in descending order: ");
    print_array(arr, size);

    return 0;
}