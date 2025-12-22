#include <stdio.h>
#include <stdlib.h>

void countingSort(int a[], int n, const char *outputFile) {
    // Hamgiin tom toog oloh
    int max = a[0];
    for (int i = 1; i < n; i++) {
        if (a[i] > max)
            max = a[i];
    }
    // Husnegt uusgeh
    int *count = (int *)calloc(max + 1, sizeof(int)); // hamgiin tom too max bol 0 s ehlsn gej bodood max+1 hemjeetei bolgono
    if (!count) {
        printf("Memory allocation failed\n");
        return;
    }

    // Too tooloh
    for (int i = 0; i < n; i++)
        count[a[i]]++;

    // Eremblegdsen toonuudiig filed hadgalah
    FILE *fp = fopen(outputFile, "w");
    if (!fp) {
        printf("Could not open output file.\n");
        free(count);
        return;
    }

    for (int i = 0; i <= max; i++) {
        while (count[i]--) {
            fprintf(fp, "%d ", i);
        }
    }

    fclose(fp);
    free(count);

    printf("Sorting completed. Output saved to %s\n", outputFile);
}

int main() {
    char outputFile[] = "numbersSorted.txt";

    FILE *fp = fopen("numbers.txt", "r");
    if (!fp) {
        printf("Could not open input file.\n");
        return 1;
    }

    int n;
    fscanf(fp, "%d", &n);

    int *a = (int *)malloc(n * sizeof(int));
    if (!a) {
        printf("Memory allocation failed.\n");
        fclose(fp);
        return 1;
    }

    for (int i = 0; i < n; i++)
        fscanf(fp, "%d", &a[i]);

    fclose(fp);

    countingSort(a, n, outputFile);

    free(a);
    return 0;
}
