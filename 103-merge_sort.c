#include <stdio.h>
#include <stdlib.h>

void print_array(const int *array, size_t size);
void merge(int *array, int *left, size_t left_size, int *right, size_t right_size);
void merge_sort_recursive(int *array, size_t size);

/**
 * print_array - Prints an array.
 * @array: The array to print.
 * @size: The size of the array.
 */
void print_array(const int *array, size_t size)
{
    size_t i;

    for (i = 0; i < size; i++)
    {
        printf("%d", array[i]);
        if (i < size - 1)
            printf(", ");
    }
    printf("\n");
}

/**
 * merge_sort - Sorts an array of integers in ascending order using Merge sort.
 * @array: The array to be sorted.
 * @size: The size of the array.
 */
void merge_sort(int *array, size_t size)
{
    if (array == NULL || size < 2)
        return;

    merge_sort_recursive(array, size);
}

/**
 * merge_sort_recursive - Recursive function to perform the Merge sort algorithm.
 * @array: The array to be sorted.
 * @size: The size of the array.
 */
void merge_sort_recursive(int *array, size_t size)
{
    if (size < 2)
        return;

    size_t mid = size / 2;
    int *left = array;
    int *right = array + mid;

    merge_sort_recursive(left, mid);
    merge_sort_recursive(right, size - mid);

    printf("Merging...\n");
    printf("[left]: ");
    print_array(left, mid);
    printf("[right]: ");
    print_array(right, size - mid);

    merge(array, left, mid, right, size - mid);

    printf("[Done]: ");
    print_array(array, size);
}

/**
 * merge - Merges two sub-arrays into a sorted array.
 * @array: The original array.
 * @left: The left sub-array.
 * @left_size: The size of the left sub-array.
 * @right: The right sub-array.
 * @right_size: The size of the right sub-array.
 */
void merge(int *array, int *left, size_t left_size, int *right, size_t right_size)
{
    size_t i = 0, j = 0, k = 0;
    int *merged_array = malloc((left_size + right_size) * sizeof(int));

    if (merged_array == NULL)
    {
        perror("Failed to allocate memory");
        exit(EXIT_FAILURE);
    }

    while (i < left_size && j < right_size)
    {
        if (left[i] <= right[j])
        {
            merged_array[k] = left[i];
            i++;
        }
        else
        {
            merged_array[k] = right[j];
            j++;
        }
        k++;
    }

    while (i < left_size)
    {
        merged_array[k] = left[i];
        i++;
        k++;
    }

    while (j < right_size)
    {
        merged_array[k] = right[j];
        j++;
        k++;
    }

    for (k = 0; k < left_size + right_size; k++)
    {
        array[k] = merged_array[k];
    }

    free(merged_array);
}
