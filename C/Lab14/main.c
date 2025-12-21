#include "student.h"

int main(){

    int n, cmd,i;

    Student a[200];
        FILE *fin = NULL;
        fin = fopen("C:\\Users\\Uuganbayar\\Downloads\\students.txt", "r");
        if (!fin) {
                printf("input file error!\n");
                exit(-1);
        }
       fscanf(fin, "%d", &n);

        for (i = 0; i < n; i++) {
                fscanf(fin, "%s%d%f", a[i].fname, &a[i].age, &a[i].gpa);
        }
        fclose(fin);

    print_students(a, n);

    char name[20];
    int age;
    float gpa;

    while (1) {
        printf("1: Nereer xaix, 2: Age-aar xaix, 3: GPA-aar xaix, 4: GPA erembelex, 5: Age-aar erembelex, 6: Nereer erembelex, 7: Xevlex, 8: Garax\n");
        scanf("%d", &cmd);
        if (cmd == 1) {
            printf("Xaix ner: ");
            scanf("%s", name);
            // ovogoor haigaad oldvol hevleh



        }  else if (cmd == 2) {
            printf("Xaix age: ");
            scanf("%s", age);
            // id-aar haigaad oldvol hevleh


        } else if (cmd == 3) {
            printf("Xaix GPA: ");
            scanf("%f", &gpa);
            // golchooroor haigaad oldvol hevleh


        }
        else if (cmd == 4){
            //GPA erembeleh

        }
        else if (cmd == 5){
            //Age-eer erembeleh

        }
        else if (cmd == 6){
            //nereer erembeleh

        }
        else if(cmd == 7)
            print_students(a, n);
        else
            break;
    }

    return 0;
}
