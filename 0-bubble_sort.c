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
	int n, i, j;

	n = size;

	for (i = 0; i < n - 1; i++)
	{
		for (j = 0; j < n - i - 1; j++)
		{
			if (array[j] > array[j + 1])
			{
				swap_func(&array[j], &array[j + 1]);
			}
		}
	}
}

/**
*swap_func - this function swap the value of x and y
*@x: The first value
*@y: The second value
*Return: Nothing
*/
void swap_func(int *x, int *y)
{

	int tmp = *x;
	*x = *y;
	*y = tmp;
}