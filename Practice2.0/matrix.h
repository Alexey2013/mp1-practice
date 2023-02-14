#ifndef _MATRIX_H
#define _MATRIX_H

typedef struct
{
    int n;
    float * x;
} Tmatrix;

void alloc_matrix(Tmatrix** matrix, int n);
void free_matrix(Tmatrix** matrix);
void fill_matrix(Tmatrix* matrix);
void print_matrix(Tmatrix* matrix);
Tmatrix* add_matrix(Tmatrix* m1, Tmatrix* m2);
Tmatrix* add_number(Tmatrix* matrix, double c);
Tmatrix* multi_matrix(Tmatrix* m1, Tmatrix* m2);
Tmatrix* multi_number(Tmatrix* matrix, double c);

#endif // !_MATRIX_H
