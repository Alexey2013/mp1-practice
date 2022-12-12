#include "qsort.h"

struct _file
{
	char name[20];
	int size;
};

void qsort(struct _file** m, int size_of_m, int start) {
	int i = 0;
	int j = size_of_m - 1;
	int mid;
	struct _file tmp;
	mid = (*m)[start + size_of_m / 2].size;
	do {
		while ((*m)[start + i].size < mid) { i++; }
		while ((*m)[start + j].size >= mid) { j--; }
		if (i <= j) {
			if ((*m)[start + i].size > (*m)[start + j].size) {
				tmp.size = (*m)[start + i].size;
				(*m)[start + i].size = (*m)[start + j].size;
				(*m)[start + j].size = tmp.size;
			}
		}
	} while (i <= j);
	if (size_of_m == 2)return;
	if (j > 0) { qsort(m, j + 1, 0); }
	if (i < size_of_m - 1) { qsort(m, size_of_m - i, i); }
}