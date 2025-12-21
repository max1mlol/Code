#include "student.h"



void print_students(Student a[], int n){
    for (int i = 0; i < n; i++){
        print(&a[i]);
    }
}

void print(Student *st){
    printf("Ner: %s\n", st->fname);
    printf("Age: %d\n", st->age);
    printf("GPA: %.1f\n", st->gpa);
}
