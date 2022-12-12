#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <stdlib.h>
#include <limits.h>
#include <time.h>
#include "merge.h"
#include "qsort.h"
#include "choice_min.h"
#define N 10

struct _file
{
	char name[20];
	int size;
};

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