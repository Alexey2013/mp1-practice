#include "qsort.h"

struct file
{
	char name[20];
	int size;
};


void qsort(struct file* files, int size) {
    int i = 0;
    int j = size - 1;
    struct file tmp;
    int mid = files[size / 2].size;
    do {
        while (files[i].size < mid) {
            i++;
        }

        while (files[j].size > mid) {
            j--;
        }

        if (i <= j) {
            tmp = files[i];
            files[i] = files[j];
            files[j] = tmp;

            i++;
            j--;
        }
    } while (i <= j);

    if (j > 0) {
        qsort(files, j + 1);
    }
    if (i < size) {
        qsort(&files[i], size - i);
    }
}
