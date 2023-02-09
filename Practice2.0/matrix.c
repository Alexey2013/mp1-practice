#define _CRT_SECURE_NO_WARNINGS
#include <stdlib.h>
#include <stdio.h>
#include "matrix.h"

void alloc_matrix(Tmatrix**matrix, int n,int m)
{
    int i;
    *matrix = (Tmatrix*)malloc(sizeof(Tmatrix)*1);
    (*matrix)->n=n;
    (*matrix)->m= m;
    (*matrix)->x = (double**)malloc(sizeof(double*) * n);
    for (int i = 0; i < n; i++) {
        (*matrix)->x[i] = (double*)malloc(m* sizeof(double));
    }
}

void free_matrix(Tmatrix** matrix)
{
    free((*matrix)->x);
    free(*matrix);
}


void fill_matrix(Tmatrix* matrix)
{
    int i = 0;
    int j = 0;
    for (; i < matrix->n; i++)
    {
        for (; j < matrix->n; j++)
        scanf("%lf", &(matrix->x[i][j]));
    }
}

void print_matrix(Tmatrix* matrix)
{
    int j = 0;
    int i = 0;
    for (; i < matrix->n; i++)
    {
        for (; j < matrix->n; j++)
            printf("%3d ", matrix->x[i][j]);
        printf("\n");
    }
}

Tmatrix* add_matrix(Tmatrix* m1, Tmatrix* m2)
{
    Tmatrix* res;
    int i = 0;
    int j = 0;
    alloc_matrix(&res, m1->n, m1->n);
    for (; i < res->n; i++)
    {
        for (; j < res->n; j++)
        {
            res->x[i][j] = m1->x[i][j] + m2->x [i][j];
        }
    }
    return res;
}

Tmatrix* add_number(Tmatrix* matrix, double c)
{
    Tmatrix* res;
    int i = 0;
    int j = 0;
    alloc_matrix(&res, matrix->n, matrix->n);
    for (; i < res->n; i++)
    {
        for (; j < res->n; j++) {
        res->x[i][j] = matrix->x[i][j] + c;
    }
    }
    return res;
}

Tmatrix * multi_matrix(Tmatrix* m1, Tmatrix* m2)
{
    Tmatrix* res;
    int i = 0;
    int j = 0;
    alloc_matrix(&res, m1->n, m1->n);
    for (; i < res->n; i++)
    {
        for (; j < res->n; j++)
        {
            res->x[i][j] +=m1->x[i][j] * m2->x[i][j];
        }
    }
    return res;
}


Tmatrix* multi_number(Tmatrix* matrix, double c)
{
    Tmatrix* res;
    int i = 0;
    int j = 0;
    alloc_matrix(&res, matrix->n, matrix->n);
    for (; i < res->n; i++)
    {
        for (; j < res->n; j++) {
            res->x[i][j] = matrix->x[i][j] * c;
        }
    }
    return res;
}
