#include "qsort.h"

struct _file
{
	char name[20];
	int size;
};


void qsort(struct _file** m, int size_of_m, int start) {
	int i = start;
	int j = size_of_m;
	int mid;
	struct _file tmp;
	mid = (*m)[(start + size_of_m) / 2].size;
	do {
		while ((*m)[i].size < mid) { i++; }
		while ((*m)[j].size >= mid) { j--; }
		if (i <= j) {
			tmp.size = (*m)[i].size;
			(*m)[i].size = (*m)[j].size;
			(*m)[j].size = tmp.size;
			i++;
			j--;
		}
	} while (i < j);
	if (size_of_m == 2) return;
	if (j > 0) { qsort(m, j, 0); }
	if (i < size_of_m - 1) { qsort(m, size_of_m, i + 1); }
}
