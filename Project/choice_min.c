#include "choice_min.h"
#include <stdlib.h>

struct _file
{
	char name[20];
	int size;
};

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
