#include <stdio.h>
#include <string.h>

struct Student{
    char fname[20];
    int age[20];
    float gpa;
};
typedef struct Student Student;

void print_students(Student a[], int n);
void print(Student *st);
