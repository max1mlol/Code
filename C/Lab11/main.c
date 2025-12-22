#include "array.h"

int main(){
    int *array;
    int sz, s;
    printf("Size of array:\n");
    scanf("%d", &sz);//husnegtiin hemjee asuuh
    array = createArray(sz);
    read(array, sz);
    print(array, sz);
    printf(" min of elements: %d\n", minA(array, sz));
    printf(" max of elements: %d\n", maxA(array, sz));
    printf(" average of elements: %.2f\n", average(array, sz));
    printf("Enter element to search:\n");
    scanf("%d", &s);

    int idx = searchA(array, sz, s);
    if (idx != -1){
        printf(" element index: %d\n", idx);

    }
    else{
        printf(" element not found\n");

    }

    sortA(array, sz);
    printf("After sorting:\n");
    print(array, sz);
    deleteArray(array);
    return 0;
}
