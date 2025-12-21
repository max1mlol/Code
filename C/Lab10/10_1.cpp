#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <ctype.h>
#include <string.h>

int main()
{
    char f[100], longestWord[100] = "";
    printf("File: ");
    scanf("%s", f);

    FILE *fptr = fopen(f, "r");
    FILE *fptr2 = fopen("result2.txt", "w");
    if (fptr == NULL)
    {
        printf("Error opening file.\n");
        return 1;
    }
    int c, words = 0, sentences = 0, count = 0, max = 0, i;
    char longword[100] = "", longword2[100] = "";
    bool space = true;

    while (true)
    {
        c = fgetc(fptr);
        
        if (feof(fptr))
        {
            break;
        }
        else if (ferror(fptr))
        {
            printf("Error reading file.\n");
            return 1;
        }
        
        if (space && !isspace(c))
        {
            words++;
            space = false;
        }
        else if (!space && isspace(c))
        {
            space = true;
        }
        if (c == '.' || c == '!' || c == '?')
        {
            sentences++;
        }
        /*
        if (c != ' ' || c != '.' || c != '!' || c != '?'){
            count++;
            i++;
            longword[i] = c;
        }
        else{
            if (count > max)
            {
                max = count;
                strcpy(longword2, longword);
            }
            count = 0;
            i = 0;
        }
        */
    }
    fclose(fptr);
    fprintf(fptr2, "Words: %d\n", words);
    fprintf(fptr2, "Sentences: %d\n", sentences);
    fprintf(fptr2 ,"Longest Word: %d\n", longword2);
    return 0;
}
