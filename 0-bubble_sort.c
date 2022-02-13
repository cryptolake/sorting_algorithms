#include "sort.h"
#include <stdlib.h>

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
* bubble_sort - bubble sort algorithm
* @array: array to sort
* @size: size of array
**/
void bubble_sort(int *array, size_t size)
{
	int swapped = 1;
	size_t i;

	if (size < 1)
		return;

	do {
		swapped = 0;
		for (i = 1; i < size; i++)
		{
			if (array[i - 1] > array[i])
			{
				swap(&array[i - 1], &array[i]);
				print_array(array, size);
				swapped = 1;
			}
		}

	} while (swapped);
}

