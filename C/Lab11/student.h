#ifndef STUDENT_H
#define STUDENT_H

// Student struct
typedef struct {
    char name[30];
    int id;
    float gpa;
} Student;

// Function prototypes
void readStudents(Student a[], int n);
void printStudents(Student a[], int n);

int searchByName(Student a[], int n, const char *name);
int searchById(Student a[], int n, int id);

void sortByName(Student a[], int n);
void sortById(Student a[], int n);
void sortByGPA(Student a[], int n);

#endif
