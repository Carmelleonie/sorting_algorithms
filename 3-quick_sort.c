#include "sort.h"

/*
*swap - swaps two integers
*@val1: pointer to the first value
*@val2: pointer to the second value
*Return: Nothing 
*/
void swap(int *val1, int *val2)
{
	int temp;

	temp = *val1;
	*val1 = *val2;
	*val2 = temp;
}

/*
*partition - divides the array into two partitions
*@array: the array to sort
*@size: the size of the array
*@low: the lowest index of the array
*@high: the highest index of the array
*Return: the partition index
*/
int partition(int *array, size_t size, int low, int high)
{
	int *pivot, a, b;

	pivot = array + high;

	for (a = b = low; b < high; b++)
	{
		if (*(array + b) < *pivot)
		{
			if (a < b)
			{
				swap(array + b, array + a);
				print_array(array, size);
			}
			/*Case swap occurs increment  a by 1 else do nothing*/
			a++;
		}
	}
	if (*(array + a) > *pivot)
	{
		swap((array + a), pivot);
		print_array(array, size);
	}
	return (a);
}

/*
*partition_sort - Implement the quicksort algorithm through recursion.
*@array: the array to sort
*@size: the size of the array
*@low: the lowest index of the array
*@high: th highest index of the array
*/
void partition_sort(int *array, size_t size, int low, int high)
{
	int part;

	if (low < high)
	{
		part = partition(array, size, low, high);
		partition_sort(array, size, low, part - 1);
		partition_sort(array, size, part + 1, high);
	}
}

/*
*quick_sort - sorts an array of integers in ascending order
*@array: the array to sort
*@size: the size of the array
*Return : void
*/
void quick_sort(int *array, size_t size)
{
	if (!array || size < 2)
	{
		return;
	}
	partition_sort(array, size, 0, size - 1);
}
