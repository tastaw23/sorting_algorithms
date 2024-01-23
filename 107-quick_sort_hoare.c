#include <stdio.h>
#include "sort.h"

/**
 * quick_sort_hoare - Sorts an array of integers in ascending order using
 *                    the Quick sort algorithm with Hoare partition scheme.
 * @array: Array to be sorted
 * @size: Number of elements in the array
 */
void quick_sort_hoare(int *array, size_t size)
{
    if (array == NULL || size < 2)
        return;

    quicksort_hoare(array, 0, size - 1, size);
}

/**
 * quicksort_hoare - Recursive function to perform Quick sort with Hoare scheme
 * @array: Array to be sorted
 * @low: Starting index of the partition
 * @high: Ending index of the partition
 * @size: Number of elements in the array
 */
void quicksort_hoare(int *array, int low, int high, size_t size)
{
    if (low < high)
    {
        int pivot_index = hoare_partition(array, low, high, size);
        quicksort_hoare(array, low, pivot_index, size);
        quicksort_hoare(array, pivot_index + 1, high, size);
    }
}

/**
 * hoare_partition - Partitions the array using Hoare scheme for Quick sort
 * @array: Array to be sorted
 * @low: Starting index of the partition
 * @high: Ending index of the partition
 * @size: Number of elements in the array
 * Return: Index of the pivot element after partition
 */
int hoare_partition(int *array, int low, int high, size_t size)
{
    int pivot = array[low + (high - low) / 2];
    int i = low - 1, j = high + 1;

    while (1)
    {
        do
        {
            i++;
        } while (array[i] < pivot);

        do
        {
            j--;
        } while (array[j] > pivot);

        if (i >= j)
            return j;

        swap(&array[i], &array[j]);
        print_array(array, size);
    }
}

/**
 * swap - Swaps two elements in an array
 * @a: Pointer to the first element
 * @b: Pointer to the second element
 */
void swap(int *a, int *b)
{
    int temp = *a;
    *a = *b;
    *b = temp;
}

