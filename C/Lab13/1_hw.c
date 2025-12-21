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
    // Calculate total length
    size_t total_len = 0;
    for(int i=0; i<count; i++){
        total_len += strlen(va_arg(args, char *));
    }
    va_end(args);

    // Allocate memory for concatenated string
    char *result = (char *)malloc(total_len + 1);
    if(!result){
        return NULL;
    }
    result[0] = '\0';

    // Concatenate strings
    va_start(args, count);
    for(int i=0 ;i<count; i++){
        strcat(result, va_arg(args, char *));
    }
    va_end(args);

    return result;
}

int main(){
    char *combined = concatenate_strings(3, "Hello, ", "world", "!");
    printf("%s\n", combined);
    free(combined);
    return 0;
}