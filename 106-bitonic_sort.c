#include "sort.h"
#include <stdio.h>

/**
 * bitonic_merge - Merges two subarrays in a bitonic manner
 *
 * @array: Array to be merged
 * @low: Starting index of the first subarray
 * @count: Number of elements to be merged
 * @dir: 1 for ascending order, 0 for descending order
 */
void bitonic_merge(int *array, size_t low, size_t count, int dir)
{
    size_t i, k, j;
    int temp;

    if (count > 1)
    {
        k = count / 2;
        for (i = low; i < low + k; i++)
        {
            if ((array[i] > array[i + k]) == dir)
            {
                temp = array[i];
                array[i] = array[i + k];
                array[i + k] = temp;
            }
        }
        bitonic_merge(array, low, k, dir);
        bitonic_merge(array, low + k, k, dir);
    }
}

/**
 * bitonic_sort_recursive - Recursive function to perform bitonic sort
 *
 * @array: Array to be sorted
 * @low: Starting index of the subarray
 * @count: Number of elements in the subarray
 * @dir: 1 for ascending order, 0 for descending order
 */
void bitonic_sort_recursive(int *array, size_t low, size_t count, int dir)
{
    size_t k;

    if (count > 1)
    {
        k = count / 2;

        printf("Merging [%lu/%lu] (%s):\n", count, count, (dir == 1) ? "UP" : "DOWN");
        print_array(array + low, count);

        bitonic_sort_recursive(array, low, k, 1);
        bitonic_sort_recursive(array, low + k, k, 0);

        bitonic_merge(array, low, count, dir);

        printf("Result [%lu/%lu] (%s):\n", count, count, (dir == 1) ? "UP" : "DOWN");
        print_array(array + low, count);
    }
}

/**
 * bitonic_sort - Sorts an array of integers in ascending order
 *                using the Bitonic sort algorithm.
 *
 * @array: The array to be sorted
 * @size: Size of the array
 */
void bitonic_sort(int *array, size_t size)
{
    int up = 1;

    if (size > 1 && (size & (size - 1)) == 0)
    {
        bitonic_sort_recursive(array, 0, size, up);
    }
    else
    {
        fprintf(stderr, "Error: Size must be a power of 2.\n");
    }
}

