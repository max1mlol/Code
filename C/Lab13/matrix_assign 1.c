#include <stdio.h>
#include <stdlib.h>

struct Matrix {
    int rows; // murnii too
    int cols; // baganii too
    double** data; // murnuud ruu zaadag n_rows pointeriin array ruu zaadag pointer
};
typedef struct Matrix Matrix;

void print_matrix(Matrix* m) {
    if (m == NULL) return;
    for (int x = 0; x < m->rows; x++) {
        for (int y = 0; y < m->cols; y++) {
            printf("%.1f ", m->data[x][y]);
        }
        printf("\n");
    }
}

// n_rows x n_cols hemjeetei shine array uusgene. callocoor buh utguudiig 0 bolgono.
Matrix* make_matrix(int n_rows, int n_cols) {
    Matrix *matrix = (Matrix*)malloc(sizeof(Matrix));
    matrix->rows = n_rows;
    matrix->cols = n_cols;
    matrix->data = (double**)malloc(sizeof(double*) * n_rows);
    for (int x = 0; x < n_rows; x++) {
        matrix->data[x] = (double*)calloc(n_cols, sizeof(double));
    }
    return matrix;
}

Matrix* copy_matrix(double* data, int n_rows, int n_cols) {
    Matrix *matrix = make_matrix(n_rows, n_cols);
    for (int x = 0; x < n_rows; x++) {
        for (int y = 0; y < n_cols; y++) {
            matrix->data[x][y] = data[n_cols*x + y];
        }
    }
    return matrix;
}

//husnegt ruu utguudiig oruulna.
int get_matrix(Matrix* matrix) {
    printf("Enter the matrix elements %dx%d", matrix->rows, matrix->cols);
    printf("\n");
    if (matrix != NULL) {
        for (int x = 0; x < matrix->rows; x++) {
            for (int y = 0; y < matrix->cols; y++) {
                double a;
                scanf("%lf", &a);
                matrix->data[x][y] = a;
            }
        }
    } else
        return 1;

    return 0;
}
Matrix* add_two_matrix(Matrix* a, Matrix* b){
//2 матрицийн нэмэх үйлдлийг хийх функцийг хэрэгжүүлэх. Ингэхдээ шинэ матриц үүсгээд түүндээ хариуг оноон, уг матрицийн хаягаа буцаана.

if (a == NULL || b == NULL) { 
    fprintf(stderr, "add_two_matrix: Array dutuu oruulsn baina\n");
    return NULL;
}
if (a->rows != b->rows || a->cols != b->cols) { // adilhan hamjeetei esehiig shalgana
    fprintf(stderr, "add_two_matrix: Uur hemjeetei arrayuud baina (%dx%d) vs (%dx%d)\n",
            a->rows, a->cols, b->rows, b->cols);
    return NULL;
}

Matrix* res = make_matrix(a->rows, a->cols);
for (int i = 0; i < a->rows; ++i) {
    for (int j = 0; j < a->cols; ++j) {
        res->data[i][j] = a->data[i][j] + b->data[i][j];
    }
}
    return res;
}

Matrix* sub_two_matrix(Matrix* a, Matrix* b){
    //2 матрицийн хасах үйлдлийг хийх функцийг хэрэгжүүлэх. Ингэхдээ шинэ матриц үүсгээд түүндээ хариуг оноон, уг матрицийн хаягаа буцаана.

    if (a == NULL || b == NULL) {
        fprintf(stderr, "sub_two_matrix: Array dutuu oruulsn baina\n");
        return NULL;
    }
    if (a->rows != b->rows || a->cols != b->cols) {
        fprintf(stderr, "sub_two_matrix: Uur hemjeetei arrayuud baina (%dx%d) vs (%dx%d)\n",
                a->rows, a->cols, b->rows, b->cols);
        return NULL;
    }
    Matrix* res = make_matrix(a->rows, a->cols);
    for (int i = 0; i < a->rows; ++i) {
        for (int j = 0; j < a->cols; ++j) {
            res->data[i][j] = a->data[i][j] - b->data[i][j];
        }
    }
    return res;
}

Matrix* mul_two_matrix(Matrix* a, Matrix* b){
    //2 матрицийн үржих үйлдлийг хийх функцийг хэрэгжүүлэх. Ингэхдээ шинэ матриц үүсгээд түүндээ хариуг оноон, уг матрицийн хаягаа буцаана.

    if (a == NULL || b == NULL) {
        fprintf(stderr, "mul_two_matrix: Array dutuu oruulsn baina\n");
        return NULL;
    }
    if (a->cols != b->rows) { // a giin bagana ni b giin murtei tentsuu esehig shalgana
        fprintf(stderr, "mul_two_matrix: Uur hemjeetei arrayuud baina for multiplication (%dx%d) * (%dx%d)\n",
                a->rows, a->cols, b->rows, b->cols);
        return NULL;
    }
    Matrix* res = make_matrix(a->rows, b->cols);
    for (int i = 0; i < a->rows; ++i) {
        for (int j = 0; j < b->cols; ++j) {
            double sum = 0.0;
            for (int k = 0; k < a->cols; ++k) {
                sum += a->data[i][k] * b->data[k][j];
            }
            res->data[i][j] = sum;
        }
    }
    return res;
}
void delete_matrix(Matrix* m){
//энэ функцийг хэрэгжүүлэх, тухайн матрицийн нөөцөлсөн санах ойнуудыг чөлөөлөх

if (m == NULL) return;
if (m->data != NULL) {
    for (int i = 0; i < m->rows; ++i) {
        free(m->data[i]);
    }
    free(m->data);
}
free(m);

}
int main(void) {

    Matrix* r1;
    Matrix* m1 = make_matrix(2, 2);
    get_matrix(m1);
    Matrix* m2 = make_matrix(2, 2);
    get_matrix(m2);
    print_matrix(m1);
    print_matrix(m2);

    Matrix* (*pf)(Matrix* a, Matrix* b);

  int c=1;
  while(c!=0){
      printf("1:add, 2:sub, 3:mul, 4: exit\n");
        scanf("%d",&c);
        switch(c)
        {
            case 1: pf=add_two_matrix; break;
            case 2: pf=sub_two_matrix; break;
            case 3: pf=mul_two_matrix; break;
            default: return 0;
        }
    r1 = pf(m1,m2);
    print_matrix(r1);
  }


    delete_matrix(m1);
    delete_matrix(m2);
    delete_matrix(r1);

    return 0;
}
