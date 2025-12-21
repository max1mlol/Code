#include <stdio.h>
#include <string.h>
#include "student.h"

void readStudents(Student a[], int n) {
    for (int i = 0; i < n; i++) {
        printf("\nStudent %d:\n", i + 1);
        printf("Name: ");
        scanf("%s", a[i].name);
        printf("ID: ");
        scanf("%d", &a[i].id);
        printf("GPA: ");
        scanf("%f", &a[i].gpa);
    }
}

void printStudents(Student a[], int n) {
    printf("\nID\tName\t\tGPA\n");
    printf("________________________________\n");
    for (int i = 0; i < n; i++)
        printf("%d\t%-10s\t%.2f\n", a[i].id, a[i].name, a[i].gpa);
}

int searchByName(Student a[], int n, const char *name){
    for (int i = 0; i < n; i++)
        if (strcmp(a[i].name, name) == 0)
            return i;
    return -1;
}

int searchById(Student a[], int n, int id){
    for (int i = 0; i < n; i++){
        if (a[i].id == id){
            return i;
        }
    }
    return -1;
}

void sortByName(Student a[], int n) {
    Student temp;
    for (int i = 0; i < n - 1; i++){
        for (int j = i + 1; j < n; j++){
            if (strcmp(a[i].name, a[j].name) > 0){
                temp = a[i];
                a[i] = a[j];
                a[j] = temp;
            }
        }
    }
}

void sortById(Student a[], int n){
    Student temp;
    for (int i = 0; i < n - 1; i++){
        for (int j = i + 1; j < n; j++){
            if (a[i].id > a[j].id) {
                temp = a[i];
                a[i] = a[j];
                a[j] = temp;
            }
        }
    }
}

void sortByGPA(Student a[], int n){
    Student temp;
    for (int i = 0; i < n - 1; i++){
        for (int j = i + 1; j < n; j++){
            if (a[i].gpa < a[j].gpa){
                temp = a[i];
                a[i] = a[j];
                a[j] = temp;
            }
        }
    }
}
