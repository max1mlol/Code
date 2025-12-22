#include<stdio.h>
#include<stdarg.h>
#include<limits.h>
int max_integers(int count, ...) { //huvisah argument
    if(count <=0){
        return INT_MIN; //hamgiin baga utgiig butsaana -265354675976086768795765
    }
    va_list args;
    va_start(args, count); //3 ruu ehleed zaana
    int max = va_arg(args, int); //ehni ugta, int turliin utga unshina
    for(int i=1;i<count;i++){
        int current = va_arg(args, int); //odo bga toog unshaad daraginhruu shiljene
        if(current > max){
            max = current;
        }
    }
    va_end(args); //tseverleh
    return max;
}
int main(){
    printf("Max: %d\n", max_integers(6, 3, 7, 2, 9, 1));
    return 0;
}