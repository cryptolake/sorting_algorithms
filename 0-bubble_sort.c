#include "sort.h"
#include <stdlib.h>

void swap(int *ele0, int *ele1)
{
	int swape;

	swape = *ele0;

	*ele0 = *ele1;

	*ele1 = swape;
}


void bubble_sort(int *array, size_t size)
{
	int swapped;
	size_t i;
	do {
		swapped = 0;
		for (i = 1; i < size; i++)
		{
			if (array[i-1] > array[i])
			{
				swap(&array[i-1], &array[i]);
				print_array(array, size);
				swapped = 1;
			}
				
		}

	} while (swapped);
}

