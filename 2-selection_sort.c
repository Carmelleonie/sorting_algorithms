#include "sort.h"


void selection_sort(int *array, size_t size)
{
	int i, j, min, n = size, temp;


	if (!array || size < 2)
	{
		return;
	}
	for (i = 0; i < (n - 1); i++)
	{
		temp = array[min];
		min = i;
		for (j = i + 1; j < n; j++)
		{
			if (array[j] < array[min])
			{
				min = j;
			}
		}
		if (array[min] != array[i])
		{
			array[min] = array[j];
			array[j] = temp;
			print_array(array, size);
		}
	}
}
