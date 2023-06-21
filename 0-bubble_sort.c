#include "sort.h"

/**
*bubble_sort - a function that sorts an array
*of integers in ascending order using the
*Bubble sort algorithm
*@array: array of size n to be sorted
*@size: the lenght of the array
*Return: Nothing
*/

void bubble_sort(int *array, size_t size)
{
	int n, i, j, tmp;

	n = size;

	if (size < 2)
	{
		return;
	}

	for (i = 0; i < n - 1; i++)
	{
		for (j = 0; j < n - i - 1; j++)
		{
			if (array[j] > array[j + 1])
			{
				tmp = array[j];
				array[j] = array[j + 1];
				array[j + 1] = tmp;
				print_array(array, size);
			}
		}
	}
}
