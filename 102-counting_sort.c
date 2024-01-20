#include <stdio.h>
#include <stdlib.h>
#include "sort.h"

/**
 * counting_sort - Sorts an array of integers in ascending order using
 *                 the Counting sort algorithm.
 * @array: The array to be sorted.
 * @size: The size of the array.
 */
void counting_sort(int *array, size_t size)
{
    if (array == NULL || size < 2)
        return;

    size_t i;
    size_t max;  /* Change the type of max to size_t */

    /* Find the maximum value in the array */
    max = array[0];
    for (i = 1; i < size; i++)
    {
        if ((size_t)array[i] > max)
            max = (size_t)array[i];
    }

    /* Declare variables at the beginning of the function */
    size_t j;
    int *counting_array;

    /* Create a counting array with size (max + 1) */
    counting_array = malloc((max + 1) * sizeof(int));
    if (counting_array == NULL)
        return;

    /* Initialize counting array elements to 0 */
    for (i = 0; i <= max; i++)
        counting_array[i] = 0;

    /* Populate counting array with frequency of each element */
    for (i = 0; i < size; i++)
        counting_array[array[i]]++;

    /* Print counting array */
    print_array(counting_array, max + 1);

    /* Update the original array based on counting array */
    j = 0;
    for (i = 0; i <= max; i++)
    {
        while (counting_array[i] > 0)
        {
            array[j++] = i;
            counting_array[i]--;
        }
    }

    /* Free allocated memory */
    free(counting_array);
}

