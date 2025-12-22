#include<stdio.h>
#include<stdarg.h>
#include<limits.h>
int max_integers(int count, ...) { //huvisah argument
    if(count <=0){
        return INT_MIN; //hamgiin baga utgiig butsaana
    }
    va_list args;
    va_start(args, count); //ehni vaarg ru args zaagchiig chigluuleh
    int max = va_arg(args, int); //ehni ugta
    for(int i=1;i<count;i++){
        int current = va_arg(args, int);
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