#include "sort.h"

/**
 * shell_sort - Sorts an array of integers in ascending order using the
 *              Shell sort algorithm with the Knuth sequence.
 *
 * @array: Array to be sorted
 * @size: Size of the array
 */
void shell_sort(int *array, size_t size)
{
    size_t gap, i, j;
    int temp;

    if (array == NULL || size < 2)
        return;

    gap = 1;
    while (gap < size)
        gap = gap * 3 + 1;

    while (gap > 1)
    {
        gap /= 3;
        for (i = gap; i < size; i++)
        {
            temp = array[i];
            for (j = i; j >= gap && array[j - gap] > temp; j -= gap)
            {
                array[j] = array[j - gap];
            }
            array[j] = temp;
        }
        print_array(array, size);
    }
}

