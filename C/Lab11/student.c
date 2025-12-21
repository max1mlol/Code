#include <stdio.h>
#include <string.h>
#include "student.h"

// --- Oruulah ---
void readStudents(Student a[], int n) {
    for (int i = 0; i < n; i++) {
        printf("\n%d-r oyutan:\n", i + 1);
        printf("Ner: ");
        scanf("%s", a[i].name);
        printf("ID: ");
        scanf("%d", &a[i].id);
        printf("Golch: ");
        scanf("%f", &a[i].gpa);
    }
}

// --- Hevleh ---
void printStudents(Student a[], int n) {
    printf("\nID\tNer\t\tGolch\n");
    printf("________________________________\n");
    for (int i = 0; i < n; i++)
        printf("%d\t%-10s\t%.2f\n", a[i].id, a[i].name, a[i].gpa);
}

// --- Ner-eer hailt ---
int searchByName(Student a[], int n, const char *name) {
    for (int i = 0; i < n; i++)
        if (strcmp(a[i].name, name) == 0)
            return i;
    return -1;
}

// --- ID-gaar hailt ---
int searchById(Student a[], int n, int id) {
    for (int i = 0; i < n; i++)
        if (a[i].id == id)
            return i;
    return -1;
}

// --- Ner-eer erembeleh ---
void sortByName(Student a[], int n) {
    Student temp;
    for (int i = 0; i < n - 1; i++)
        for (int j = i + 1; j < n; j++)
            if (strcmp(a[i].name, a[j].name) > 0) {
                temp = a[i];
                a[i] = a[j];
                a[j] = temp;
            }
}

// --- ID-gaar erembeleh ---
void sortById(Student a[], int n) {
    Student temp;
    for (int i = 0; i < n - 1; i++)
        for (int j = i + 1; j < n; j++)
            if (a[i].id > a[j].id) {
                temp = a[i];
                a[i] = a[j];
                a[j] = temp;
            }
}

// --- GPA-gaar erembeleh ---
void sortByGPA(Student a[], int n) {
    Student temp;
    for (int i = 0; i < n - 1; i++)
        for (int j = i + 1; j < n; j++)
            if (a[i].gpa < a[j].gpa) {
                temp = a[i];
                a[i] = a[j];
                a[j] = temp;
            }
}
