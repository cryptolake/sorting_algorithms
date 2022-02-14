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
* selection_sort - sort using selection algorithm
* @array: array of integers
* @size: size of array
**/
void selection_sort(int *array, size_t size)
{
	size_t i, j, min;

	for (i = 0; i < size; i++)
	{
		min = i;
		for (j = i + 1; j < size; j++)
		{
			if (array[j] < array[min])
				min = j;
		}

		if (min != i)
		{
			swap(&array[i], &array[min]);
			print_array(array, size);
		}
	}
}
