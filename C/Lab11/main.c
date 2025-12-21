#include "array.h"

int main(){
    int *array;
    int sz, s;
    printf("uusgeh array-ni hemjee:\n");
    scanf("%d", &sz);
    array = createArray(sz);
    read(array, sz);
    print(array, sz);
    printf(" hamgiin baga ni: %d\n", minA(array, sz));
    printf(" hamgiin ih ni: %d\n", maxA(array, sz));
    printf(" elementuudiin dundaj ni: %.2f\n", average(array, sz));
    printf("haih utgiig oruul\n");
    scanf("%d", &s);

    int idx = searchA(array, sz, s);
    if (idx != -1)
        printf(" haisan elementiin index: %d\n", idx);
    else
        printf(" element oldsongui\n");

    sortA(array, sz);
    printf("eremblegdsnii daraa:\n");
    print(array, sz);
    deleteArray(array);
    return 0;
}
