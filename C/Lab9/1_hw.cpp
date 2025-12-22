#include<stdio.h>
struct Student{
    char fname[20], lname[20], id[10];
    float golch;
};
typedef struct Student Student;
void read_students(Student a[], int n);
void print_students(Student a[], int n);
void print(Student st);
int search_by_fname(Student a[], int n, char fname[]);
int search_by_lname(Student a[], int n, char lname[]);
int search_by_id(Student a[], int n, char id[]);
int search_by_golch(Student a[], int n, float golch);
void sort_by_golch(Student a[], int n);
int main(){
    Student a[100];
    int n, cmd, idx;
    printf("Oyutnii too: ");
    scanf("%d", &n);
    read_students(a, n);
    print_students(a, n);
    char fname[20], lname[20], id[20];
    float golch;
    while (1){
        printf("1: Nereer xaix, 2: Ovgoor xaix, 3: ID-aar xaix, 4: Golchoor xaix, 5: Golchoor erembeleh, 6: Xevlex, 7: Garah\n");
        scanf("%d", &cmd);
        if(cmd == 1){
            printf("Xaix ner: ");
            scanf("%s", fname);
            idx = search_by_fname(a, n, fname);
            if(idx = -1){
                printf("Oyutan oldsongui\n");
            }
            else{
                printf("%d", a[idx]);
            }
        }
        else if(cmd == 2){
            printf("Xaix ovog: ");
            scanf("%s", lname);
            idx = search_by_lname(a, n ,lname);
        }
        else if(cmd == 3){
            printf("Xaix od: ");
            scanf("%s", id);
            idx = search_by_id(a, n, id);
            if(idx = -1){
                printf("Oyutan oldsongui\n");
            }
            else{
                printf("%d", a[idx]);
            }
        }
        else if(cmd == 4){
            printf("Xaix golch: ");
            scanf("%f", &golch);
            idx = search_by_golch(a, n, golch);
            if(idx == -1){
                printf("Oyutan oldsongui\n");
            }
            else{
                printf("%d", a[idx]);
            }
        }
        else if(cmd = 5){
            sort_by_golch(a, n);
        }
        else if(cmd == 6){
            print_students(a, n);
        }
        else{
            break;
        }
        return 0;
        
    }
}