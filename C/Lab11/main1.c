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
    printf("\n===== STUDENT SYSTEM =====\n");
    printf("1. Buh oyutan hevleh\n");
    printf("2. Ner-eer hailt\n");
    printf("3. ID-gaar hailt\n");
    printf("4. Ner-eer erembeleh\n");
    printf("5. ID-gaar erembeleh\n");
    printf("6. GPA-gaar erembeleh\n");
    printf("7. Garah\n");
    printf("Songolt: ");
    scanf("%d", &idx);

    if (idx == 1) {
        printStudents(a, n);
    } 
    else if (idx == 2) {
        char name[30];
        printf("Ner oruul: ");
        scanf("%s", name);
        int idx = searchByName(a, n, name);
        if (idx != -1)
            printf("Oldson: %s %d %.2f\n", a[idx].name, a[idx].id, a[idx].gpa);
        else
            printf("Oyutan oldsongui\n");
    } 
    else if (idx == 3) {
        int id;
        printf("ID oruul: ");
        scanf("%d", &id);
        int idx = searchById(a, n, id);
        if (idx != -1)
            printf("Oldson: %s %d %.2f\n", a[idx].name, a[idx].id, a[idx].gpa);
        else
            printf("Oyutan oldsongui\n");
    }
    else if (idx == 4) {
        sortByName(a, n);
        printf("\nNer-eer eremblegdlee.\n");
        printStudents(a, n);
    }
    else if (idx == 5) {
        sortById(a, n);
        printf("\nID-gaar eremblegdlee.\n");
        printStudents(a, n);
    }
    else if (idx == 6) {
        sortByGPA(a, n);
        printf("\nGPA-gaar eremblegdlee.\n");
        printStudents(a, n);
    }
    else if (idx == 7) {
        return 0;
    }
    else {
        printf("Buruu songolt!\n");
    }

    goto MENU;
}
