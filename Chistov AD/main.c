#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <stdlib.h>
#include <limits.h>
#include <time.h>
#define N 10

struct _file
{
	char name[20];
	int size;
};

void choice_min(struct _file** m, int size_of_m);
void merge(struct _file** m, int size_of_m);
void qsort(struct _file** m, int size_of_m, int start);

int main() {
	int answer1;
	int answer2;
	char path[500];
	int n = N;
	struct _file* dir = (struct _file*)malloc(n * sizeof(struct _file));
	char _Name[N][20] = { "PRESENTATION.PPT", "COMMAND.COM", "MAINNOTE.PDF", "HELP.EXE", "GAMES_2.ARC", "BLACK1.PAS", "A.EXE", "README.TXT", "AUTOEXEC.BAT", "CONFIG.SYS" };
	int _Size[N] = { 9012 , 19012 , 293012, 123404, 51324, 10122, 21302, 79312, 5134404, 113242 };

	while (1) {
		for (int i = 0; i < N; i++)
		{
			for (int j = 0; j < 20; j++)
			{
				dir[i].name[j] = _Name[i][j];
			}
			dir[i].size = _Size[i];
		}

		printf("Methods:\n1 - selection sort,\n2 - merge sort,\n3 - quick sort.\nChoose one of the sorting methods: ");
		scanf("%d", &answer1);
		double time_spent = 0.0;
		switch (answer1)
		{
		case 1: {
			double time_spent = 0.0;
			clock_t begin = clock();
			choice_min(&dir, n);
			clock_t end = clock();
			time_spent += (double)(end - begin) / CLOCKS_PER_SEC;
			break;
		}
		case 2: {
			double time_spent = 0.0;
			clock_t begin = clock();
			merge(&dir, n);
			clock_t end = clock();
			time_spent += (double)(end - begin) / CLOCKS_PER_SEC;
			break;
		}
		case 3: {
			double time_spent = 0.0;
			clock_t begin = clock();
			qsort(&dir, N, 0);
			clock_t end = clock();
			time_spent += (double)(end - begin) / CLOCKS_PER_SEC;
			break;
		}
		default: {break; }
		}
		char Name[20] = "name";
		char Size[15] = "size, bytes";
		printf(" # %20s %15s\n", Name, Size);
		for (int i = 0; i < n; i++)
		{
			printf("%2d %20s %15d\n", i + 1, dir[i].name, dir[i].size);
		}
		printf("This sorting took %lf seconds\n", time_spent);
		system("pause");
		printf("Would you like to leave the program?(1-yes, 2-no)");
		scanf("%d", &answer2);
		switch (answer2) {
		case 1: {free(dir); return 0; }
		case 2: 	system("cls");
		}
	}
}

void choice_min(struct _file** m, int size_of_m)
{
	struct _file tmp;
	int min = INT_MAX;
	int id_min = 0;
	for (int i = 0; i < size_of_m; i++)
	{
		for (int j = i; j < size_of_m; j++)
		{
			if ((*m)[j].size < min)
			{
				min = (*m)[j].size;
				id_min = j;
			}
		}
		for (int j = 0; j < 20; j++)
		{
			(tmp.name)[j] = ((*m)[id_min].name)[j];
		}
		tmp.size = (*m)[id_min].size;

		for (int j = 0; j < 20; j++)
		{
			((*m)[id_min].name)[j] = ((*m)[i].name)[j];
		}
		(*m)[id_min].size = (*m)[i].size;

		for (int j = 0; j < 20; j++)
		{
			((*m)[i].name)[j] = (tmp.name)[j];
		}
		(*m)[i].size = tmp.size;

		min = INT_MAX;
		id_min = 0;
	}
}


void merge(struct _file** m, int size_of_m)
{
	struct _file tmp;
	int right, rend;
	int i, j, l;
	struct _file b[N];
	for (int k = 1; k < size_of_m; k *= 2)
	{
		for (int left = 0; left + k < size_of_m; left += k * 2)
		{
			right = left + k;
			rend = right + k;
			if (rend > size_of_m) rend = size_of_m;
			l = left; i = left; j = right;
			while (i < right && j < rend)
			{
				if ((*m)[i].size <= (*m)[j].size)
				{
					b[l].size = (*m)[i].size;
					for (int r = 0; r < 20; r++)
					{
						b[l].name[r] = (*m)[i].name[r];
					}
					i++;
				}
				else
				{
					b[l].size = (*m)[j].size;
					for (int r = 0; r < 20; r++)
					{
						b[l].name[r] = (*m)[j].name[r];
					}
					j++;
				}
				l++;
			}
			while (i < right)
			{
				b[l].size = (*m)[i].size;
				for (int r = 0; r < 20; r++)
				{
					b[l].name[r] = (*m)[i].name[r];
				}
				i++; l++;
			}
			while (j < rend)
			{
				b[l].size = (*m)[j].size;
				for (int r = 0; r < 20; r++)
				{
					b[l].name[r] = (*m)[j].name[r];
				}
				j++; l++;
			}

			for (l = left; l < rend; l++)
			{
				(*m)[l].size = b[l].size;
				for (int r = 0; r < 20; r++)
				{
					(*m)[l].name[r] = b[l].name[r];
				}
			}
		}
	}
}

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