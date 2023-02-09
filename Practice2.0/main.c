#define _CRT_SECURE_NO_WARNINGS
#include <stdlib.h>
#include <stdio.h>
#include "matrix.h"
#define N 4 

int main() {
	int i = 0;
	int j = 0;
	Tmatrix* m1, * m2, *res;
	alloc_matrix(&m1, N,N);
	alloc_matrix(&m2, N, n);
	fill_matrix(m1);
	fill_matrix(m2);
	printf("Result of sum of matrices with each other");
	res = add_matrix(m1, m2);
	print_matrix(res);
	free_matrix(&res);
	printf("Result of the sum of the first matrix each with a constant");
	res = add_number(m1, 2.5);
	print_matrix(res);
	free_matrix(&res);
	printf("Result of matrix multiplication with each other");
	res =multi_matrix(m1, m2);
	print_matrix(res);
	free_matrix(&res);
	printf("Result of multiplying the first matrix by a constant");
	res = multi_number(m1, 2.0);
	print_matrix(res);
	free_matrix(&res);
	print_matrix(m1);
	print_matrix(m2);
	return 0;
}
