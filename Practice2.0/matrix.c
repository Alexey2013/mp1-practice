#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <stdlib.h>
#include "matrix.h";

void alloc_matrix(Tmatrix** matrix, int n){
	*matrix = (Tmatrix*)malloc(sizeof(Tmatrix) * n);
	(*matrix)->n = n;
	(*matrix)->x = (float*)malloc(sizeof(float) * n * n);
}

void fill_matrix(Tmatrix* matrix){
	int i = 0;
	int j = 0;
	for (; i < matrix->n; i++)
	{
		for (j = 0; j < matrix->n; j++)
		{
			scanf("%f", &(matrix->x[i * matrix->n + j]));
		}
	}
}

void print_matrix(Tmatrix* matrix){
	int i = 0;
	int j = 0;
	for (; i < matrix->n; i++)
	{
		for (j = 0; j < matrix->n; j++)
		{
			printf("%0.3f ", matrix->x[i * matrix->n + j]);
		}
		printf("\n");
	}
}

void free_matrix(Tmatrix** matrix){
	free((*matrix)->x);
	free(*matrix);
}

Tmatrix* add_matrix(Tmatrix* m1, Tmatrix* m2){
	Tmatrix* res;
	int i = 0;
	int j = 0;
	alloc_matrix(&res, m1->n);
	j = res->n * res->n;
	for (; i < j; i++)
	{
		res->x[i] = m1->x[i] + m2->x[i];
	}
	return res;
}

Tmatrix* add_number(Tmatrix* matrix, double c){
	Tmatrix* res;
	int i = 0;
	alloc_matrix(&res, matrix->n);
	for (; i < res->n * res->n; i++)
	{
		res->x[i] = matrix->x[i] + c;
	}
	return res;
}

Tmatrix* multi_number(Tmatrix* matrix, double c) {
	Tmatrix* res;
	int i = 0;
	alloc_matrix(&res, matrix->n);
	for (; i < res->n * res->n; i++)
	{
		res->x[i] = matrix->x[i] * c;
	}
	return res;
}

Tmatrix* multi_matrix(Tmatrix* m1, Tmatrix* m2){
	Tmatrix* res;
	int i = 0;
	int j = 0;
	int l = 0;
	alloc_matrix(&res, m1->n);
	for (i = 0; i < res->n; i++) {
		for (j = 0; j < res->n; j++) {
			res->x[i * res->n + j] = 0;
			for (l = 0; l < res->n; l++)
				res->x[i * res->n + j] += m1->x[i * res->n + l] * m2->x[l* res->n + j];
		}
	}
	return res;
}
