#include <stdio.h>
#include <stdlib.h>
#include "sort.h"

/**
 * counting_sort - Sorts an array of integers in ascending order using
 * the Counting sort algorithm.
 * @array: The array to be sorted.
 * @size: The size of the array.
 */
void counting_sort(int *array, size_t size)
{
	if (array == NULL || size <= 1)
		return;

	size_t i;

	/* Find the maximum value in the array */
	int max = array[0];
	for (i = 1; i < size; i++)
	{
		if (array[i] > max)
			max = array[i];
	}

	/* Create counting array and initialize with zeros */
	int *counting_array;

	counting_array = malloc((max + 1) * sizeof(int));
	if (counting_array == NULL)
		return;

	for (i = 0; i <= (size_t)max; i++)
		counting_array[i] = 0;

	/* Print counting array */
	print_array(counting_array, max + 1);

	/* Update the original array based on counting array */
	size_t j = 0;
	for (i = 0; i <= (size_t)max; i++)
	{
		while (counting_array[i] > 0)
		{
			array[j++] = i;
			counting_array[i]--;
		}
	}

	/* Free dynamically allocated memory */
	free(counting_array);
}

