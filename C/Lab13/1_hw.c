#include<stdio.h>
#include<stdarg.h>
#include<string.h>
#include<stdlib.h>

char *concatenate_strings(int count, ...) {
    if(count <= 0){
        return NULL;
    }

    va_list args;
    va_start(args, count);
    // Niit urtiig oloh
    size_t total_len = 0;
    for(int i=0; i<count; i++){
        total_len += strlen(va_arg(args, char *));
    }
    va_end(args);

    // sanah oi huvaarilj uguh
    char *result = (char *)malloc(total_len + 1); //\0-d bas sanah oi ugn
    if(!result){
        return NULL;
    }
    result[0] = '\0';

    // stringuudiig niiluuleh
    va_start(args, count); // args pointer g ehluuleh
    for(int i=0 ;i<count; i++){
        strcat(result, va_arg(args, char *)); // araas ni zalgah
    }
    va_end(args);

    return result;
}

int main(){
    char *combined = concatenate_strings(3, "Programming, ", "language", " C");
    printf("%s\n", combined);
    free(combined);
    return 0;
}