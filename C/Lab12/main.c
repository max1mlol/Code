#include <stdio.h>
#include <stdlib.h>
struct Student {
        char name[30];
        int age;
        float gpa;
};
typedef struct Student Student;

int sortGPA(Student a[], int n);
int writeStudentsToFile(Student a[], int n, const char* filename);
int sortGPABubble(Student a[], int n);
int sortGPASelection(Student a[], int n);
int sortGPAInsertion(Student a[], int n);
int writeStudentsToFile(Student a[], int n, const char* filename) {
    FILE *fout = fopen(filename, "w");
    if (!fout) {
        printf("output file error!\n");
        return -1;
    }
        int i;
    for (i = 0; i < n; i++) {
        fprintf(fout, "%3.1f\t%d\t%s\n", a[i].gpa, a[i].age, a[i].name);
    }
    fclose(fout);
    return 0;
}
int main()
{
        Student a[200];
        Student b[200], tmp[200];
        FILE *fin = NULL;
        fin = fopen("students.txt", "r");
        if (!fin) {
                printf("input file error!\n");
                exit(-1);
        }
        int i, n;
       fscanf(fin, "%d", &n);

        for (i = 0; i < n; i++) {
                fscanf(fin, "%s%d%f", a[i].name, &a[i].age, &a[i].gpa);
        }
        fclose(fin);

        sortGPA(a, n);

        
        //        sortGPA(a, n) хийсэн үр дүнг файлд бичиж хадгалах,Тэгэхдээ дүнг нь эхний багананд хадгалах
        for (i = 0; i < n; i++){
                b[i] = a[i];
        }
        for (i = 0; i < n; i++){
                tmp[i] = b[i];
        }
        sortGPABubble(tmp, n);
        writeStudentsToFile(tmp, n, "bubbleSorted.txt");

        for (i = 0; i < n; i++){
                tmp[i] = b[i];
        }
        sortGPASelection(tmp, n);
        writeStudentsToFile(tmp, n, "selectionSorted.txt");

        for (i = 0; i < n; i++){
                tmp[i] = b[i];
        }
        sortGPAInsertion(tmp, n);
        writeStudentsToFile(tmp, n, "insertionSorted.txt");        

        return 0;
}
int sortGPABubble(Student a[], int n){
        int i, j, temp;
        if(n <= 1) return 0;
        for(i = 0; i < n-1; i++){
                temp = 0;
                for(j = 0; j < n-1-i; j++){
                        if(a[j].gpa < a[j+1].gpa){
                                Student tmp = a[j];
                                a[j] = a[j+1];
                                a[j+1] = tmp;
                                temp = 1;
                        }
                }
                if(!temp) break;//soliogui bol davtaltiig zogsoodog. O(n)
        }
        return 0;
}

int sortGPASelection(Student a[], int n){
        int i, j, max;
        for(i = 0; i < n-1; i++){
                max = i;
                for(j = i+1; j < n; j++){
                        if(a[j].gpa > a[max].gpa){
                                max = j;
                        }
                }
                if(max != i){
                        Student temp = a[i];
                        a[i] = a[max];
                        a[max] = temp;
                }
        }
        return 0;
}

int sortGPAInsertion(Student a[], int n){
        int i, j;
        for(i = 1; i < n; i++){
                Student key = a[i];
                j = i - 1;
                while(j >= 0 && a[j].gpa < key.gpa){
                        a[j+1] = a[j];
                        j--;
                }
                a[j+1] = key;
        }
        return 0;
}

int sortGPA(Student a[], int n){
        return sortGPABubble(a, n);
}
