#include <stdio.h>
#include "sort.h"

/**
 * swap_nodes - Swaps two nodes in a doubly linked list
 * @list: Pointer to the pointer to the head of the list
 * @start: Pointer to the node to be swapped with its next node
 */
void swap_nodes(listint_t **list, listint_t *start)
{
	if (start->prev != NULL)
		start->prev->next = start->next;
	else
		*list = start->next;

	start->next->prev = start->prev;
	start->prev = start->next;
	start->next = start->next->next;
	start->prev->next = start;

	if (start->next != NULL)
		start->next->prev = start;
}

/**
 * forward_pass - Performs the forward pass of the Cocktail shaker sort
 * @list: Pointer to the pointer to the head of the list
 * @start: Pointer to the start node for the forward pass
 * @end: Pointer to the end node for the forward pass
 * @swapped: Pointer to a variable indicating whether a swap occurred
 */
void forward_pass(listint_t **list, listint_t *start,
		listint_t *end, int *swapped)
{
	while (start->next != end)
	{
		if (start->n > start->next->n)
		{
			swap_nodes(list, start);
			*swapped = 1;
			print_list(*list);
		}
		else
		{
			start = start->next;
		}
	}
}

/**
 * cocktail_sort_list - Sorts a doubly linked list of integers in ascending
 *                      order using the Cocktail shaker sort algorithm
 * @list: Pointer to the pointer to the head of the list
 */
void cocktail_sort_list(listint_t **list)
{
	listint_t *start = *list;
	listint_t *end = NULL;
	int swapped;

	if (list == NULL || *list == NULL || (*list)->next == NULL)
		return;

	do {
		swapped = 0;
		forward_pass(list, start, end, &swapped);
		end = start;
		while (start->prev != NULL)
		{
			if (start->n < start->prev->n)
			{
				swap_nodes(list, start);
				swapped = 1;
				print_list(*list);
			}
			else
			{
				start = start->prev;
			}
		}
	} while (swapped);
}

