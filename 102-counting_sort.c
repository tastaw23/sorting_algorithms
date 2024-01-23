#include "sort.h"
#include <stdlib.h>
#include <stdio.h>

/**
 * counting_sort - Sorts an array of integers in ascending order
 *                 using the Counting sort algorithm.
 *
 * @array: The array to be sorted
 * @size: Size of the array
 */
void counting_sort(int *array, size_t size)
{
    if (array == NULL || size < 2)
        return;

    /* Find the maximum element in the array */
    int max = array[0];
    for (size_t i = 1; i < size; i++)
    {
        if (array[i] > max)
            max = array[i];
    }

    /* Create a counting array with size (max + 1) */
    int *counting_array = malloc((max + 1) * sizeof(int));
    if (counting_array == NULL)
        return;

    /* Initialize counting_array with zeros */
    for (int i = 0; i <= max; i++)
        counting_array[i] = 0;

    /* Count occurrences of each element in array */
    for (size_t i = 0; i < size; i++)
        counting_array[array[i]]++;

    /* Print the counting array */
    print_array(counting_array, max + 1);

    /* Update the original array using counting_array */
    int i = 0;
    for (int j = 0; j <= max; j++)
    {
        while (counting_array[j] > 0)
        {
            array[i++] = j;
            counting_array[j]--;
        }
    }

    /* Free the dynamically allocated memory */
    free(counting_array);
}

