#include "sort.h"
#include <stdio.h>

/**
 * heapify - Rearranges the heap to maintain the max heap property
 *
 * @array: Array to be heapified
 * @size: Size of the array
 * @i: Index of the current root
 * @n: Size of the array for printing purposes
 */
void heapify(int *array, size_t size, size_t i, size_t n)
{
    size_t largest = i;
    size_t left = 2 * i + 1;
    size_t right = 2 * i + 2;
    int temp;

    if (left < size && array[left] > array[largest])
        largest = left;

    if (right < size && array[right] > array[largest])
        largest = right;

    if (largest != i)
    {
        temp = array[i];
        array[i] = array[largest];
        array[largest] = temp;
        print_array(array, n);
        heapify(array, size, largest, n);
    }
}

/**
 * heap_sort - Sorts an array of integers in ascending order
 *             using the Heap sort algorithm.
 *
 * @array: The array to be sorted
 * @size: Size of the array
 */
void heap_sort(int *array, size_t size)
{
    if (array == NULL || size < 2)
        return;

    /* Build a max heap */
    size_t i;
    for (i = size / 2 - 1; i >= 0; i--)
        heapify(array, size, i, size);

    /* Extract elements from the heap one by one */
    for (i = size - 1; i > 0; i--)
    {
        /* Swap the current root with the last element */
        int temp = array[0];
        array[0] = array[i];
        array[i] = temp;
        print_array(array, size);

        /* Heapify the reduced heap */
        heapify(array, i, 0, size);
    }
}

