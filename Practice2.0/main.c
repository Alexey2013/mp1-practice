#define _CRT_SECURE_NO_WARNINGS
#include <stdlib.h>
#include <stdio.h>
#include "matrix.h"
#define N 3 
#define number 123

int main() {
	int i = 0;
	int j = 0;
	Tmatrix* m1, * m2, *res;
	alloc_matrix(&m1, N);
	alloc_matrix(&m2, N);
	fill_matrix(m1);
	fill_matrix(m2);
	printf("Introduced matrices:\n");
	print_matrix(m1);
	print_matrix(m2);
	printf("Result of sum of matrices with each other\n");
	res = add_matrix(m1, m2);
	print_matrix(res);
	free_matrix(&res);
	printf("Result of the sum of the first matrix each with a constant\n");
	res = add_number(m1, number);
	print_matrix(res);
	free_matrix(&res);
	printf("Result of matrix multiplication with each other\n");
	res =multi_matrix(m1, m2);
	print_matrix(res);
	free_matrix(&res);
	printf("Result of multiplying the first matrix by a constant\n");
	res = multi_number(m1, number);
	print_matrix(res);
	free_matrix(&res);
	return 0;
}
