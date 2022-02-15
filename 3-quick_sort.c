#include <stdio.h>
#include "sort.h"

/**
* swap - swap two integers
* @ele0: integer 1
* @ele1: integer 2
*
**/
void swap(int *ele0, int *ele1)
{
	int swape;

	swape = *ele0;

	*ele0 = *ele1;

	*ele1 = swape;
}

/**
 * partition - Use the lomuto partition scheme in  quicksort
 * to put all the element less than pivot before it.
 * @array: array to partition
 * @low: starting index
 * @high: last index
 * @arraysize: array size because betty doesn't like global
 * Return: return pivot index
 **/
int partition(int *array, int low, int high, size_t arraysize)
{
	int i, j;
	int pivot;

	pivot = array[high];

	i = low - 1;

	for (j = low; j <= high; j++)
	{
		if (array[j] <= pivot)
		{
			i++;
			if (i != j)
			{
				swap(&array[i], &array[j]);
				print_array(array, arraysize);
			}
			/* print_array(array, sizeof(array)); */
		}
	}

	return (i);
}

/**
 * rec_quicksort - implement the quicksort algorithm recusively
 * @low: the first index of the array
 * @high: last index of the array
 * @array: the array to sort
 * @arraysize: array size because betty doesn't like global
 * variables.
 *
 **/
void rec_quicksort(int *array, int low, int high, size_t arraysize)
{
	int pivot;

	if (low >= high || low < 0)
		return;

	pivot = partition(array, low, high, arraysize);


	/* before pivot */
	rec_quicksort(array, low, pivot - 1, arraysize);

	/* after pivot */
	rec_quicksort(array, pivot + 1, high, arraysize);
}

/**
* quick_sort - interface for the actual quicksort function
* @array: array to sort
* @size: size of array
**/
void quick_sort(int *array, size_t size)
{
	if (array != NULL && size > 1)
	{
		rec_quicksort(array, 0, size - 1, size);
	}
}
