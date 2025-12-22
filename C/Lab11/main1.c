#include <stdio.h>
#include <string.h>
#include "student.h"

int main() {
    Student a[100];
    int n, idx;

    printf("Oyutnii too oruul: ");
    scanf("%d", &n);

    readStudents(a, n);

MENU:
    printf("\nSTUDENT SYSTEM\n");
    printf("1. Print student info\n");
    printf("2. Search by Name\n");
    printf("3. Search by ID\n");
    printf("4. Sort by Name\n");
    printf("5. Sort by ID\n");
    printf("6. Sort by GPA\n");
    printf("7. Exit\n");
    printf("Selected: ");
    scanf("%d", &idx);

    if (idx == 1) {
        printStudents(a, n);
    } 
    else if (idx == 2){
        char name[30];
        printf("Enter name: ");
        scanf("%s", name);
        int idx = searchByName(a, n, name);
        if (idx != -1){
            printf("Found: %s %d %.2f\n", a[idx].name, a[idx].id, a[idx].gpa);
        }
        else{
            printf("Student not found\n");

        }
    } 
    else if (idx == 3){
        int id;
        printf("ID oruul: ");
        scanf("%d", &id);
        int idx = searchById(a, n, id);
        if (idx != -1){
            printf("Found: %s %d %.2f\n", a[idx].name, a[idx].id, a[idx].gpa);

        }
        else{
            printf("Student not found\n");

        }
    }
    else if (idx == 4){
        sortByName(a, n);
        printf("\nName sorted.\n");
        printStudents(a, n);
    }
    else if (idx == 5){
        sortById(a, n);
        printf("\nID sorted.\n");
        printStudents(a, n);
    }
    else if (idx == 6){
        sortByGPA(a, n);
        printf("\nGPA sorted.\n");
        printStudents(a, n);
    }
    else if (idx == 7){
        return 0;
    }
    else{
        printf("Error!\n");
    }

    goto MENU;
}
