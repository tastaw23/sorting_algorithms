#include "sort.h"
#include <stdlib.h>
#include <stdio.h>
#include <stdint.h>

/**
 * getMax - Get the maximum value in an array
 *
 * @array: Array to find the maximum value in
 * @size: Size of the array
 * Return: The maximum value
 */
int getMax(int *array, size_t size)
{
	int max = array[0];
	size_t i;

	for (i = 1; i < size; i++)
	{
		if (array[i] > max)
			max = array[i];
	}
	return max;
}

/**
 * countSort - Perform counting sort based on significant digit
 *
 * @array: Array to be sorted
 * @size: Size of the array
 * @exp: Current significant digit to consider
 */
void countSort(int *array, size_t size, int exp)
{
	int *output = malloc(size * sizeof(int));
	int count[10] = {0};
	size_t i;

	if (!output)
		return;

	/* Count occurrences of each digit at the current significant digit */
	for (i = 0; i < size; i++)
		count[(array[i] / exp) % 10]++;

	/* Accumulate the count array */
	for (i = 1; i < 10; i++)
		count[i] += count[i - 1];

	/* Build the output array */
	for (i = size - 1; i < SIZE_MAX; i--)
	{
		output[count[(array[i] / exp) % 10] - 1] = array[i];
		count[(array[i] / exp) % 10]--;
	}

	/* Copy the output array back to the original array */
	for (i = 0; i < size; i++)
		array[i] = output[i];

	/* Print the array after each significant digit */
	print_array(array, size);

	free(output);
}

/**
 * radix_sort - Sorts an array of integers in ascending order
 *              using the LSD Radix sort algorithm.
 *
 * @array: The array to be sorted
 * @size: Size of the array
 */
void radix_sort(int *array, size_t size)
{
	int max = getMax(array, size);
	int exp;

	for (exp = 1; max / exp > 0; exp *= 10)
		countSort(array, size, exp);
}

