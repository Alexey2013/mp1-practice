#include "merge.h"
#define N 10

struct _file
{
	char name[20];
	int size;
};


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