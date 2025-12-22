#include <stdio.h>
#include <stdlib.h>
struct Student {
        char name[30];
        int age;
        float gpa;
};
typedef struct Student Student;

int sortGPA(Student a[], int n);

int main()
{
        Student a[200];
        FILE *fin = NULL;
        FILE *fx = NULL;
        fx = fopen("studentsResult.txt", "w");
        fin = fopen("students.txt", "r");
        if (!fin) { //NULL bol uildluudiig hiine
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

        for (i = 0; i < n; i++)
                fprintf(fx, "%3.1f\t%d\t%s\n", a[i].gpa, a[i].age, a[i].name);

        //        sortGPA(a, n) хийсэн үр дүнг файлд бичиж хадгалах,Тэгэхдээ дүнг нь эхний багананд хадгалах
        


        return 0;
}
int sortGPA(Student a[], int n){
         // оюутан а хүснэгт дэхь өгөглүүдийг дүнгээр нь эрэмбэлэх үйлдлийг хийнэ.
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
                        a [max] = temp;
                }
        }
        return 0;
}
