#include "sort.h"

/**
 * swap_nodes - Swaps two nodes in a doubly linked list.
 * @left: The left node to be swapped.
 * @list: Double pointer to the head of the doubly linked list.
 */
void swap_nodes(listint_t *left, listint_t **list)
{
    listint_t *right = left->next;

    left->next = right->next;
    if (right->next != NULL)
        right->next->prev = left;

    right->prev = left->prev;
    right->next = left;
    left->prev = right;

    if (right->prev != NULL)
        right->prev->next = right;
    else
        *list = right;
}

/**
 * cocktail_sort_list - Sorts a doubly linked list of integers in ascending order
 *                      using the Cocktail shaker sort algorithm.
 * @list: Double pointer to the head of the doubly linked list.
 */
void cocktail_sort_list(listint_t **list)
{
    listint_t *current;
    int swapped;

    if (list == NULL || *list == NULL || (*list)->next == NULL)
        return;

    do {
        swapped = 0;
        for (current = *list; current->next != NULL; current = current->next)
        {
            if (current->n > current->next->n)
            {
                swap_nodes(current, list);
                swapped = 1;
                print_list(*list);
            }
        }

        if (swapped == 0)
            break;

        swapped = 0;
        for (; current->prev != NULL; current = current->prev)
        {
            if (current->n < current->prev->n)
            {
                swap_nodes(current->prev, list);
                swapped = 1;
                print_list(*list);
            }
        }

    } while (swapped);
}

