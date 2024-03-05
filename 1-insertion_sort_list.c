#include <stdio.h>
#include <stdlib.h>
#include "sort.h"

/**
 * insertion_sort_list - Sorts a doubly linked list of integers in ascending
 *                       order using the Insertion sort algorithm
 * @list: Pointer to the pointer to the head of the list
 */
void insertion_sort_list(listint_t **list)
{
	listint_t *current, *temp;

	if (list == NULL || *list == NULL || (*list)->next == NULL)
		return;

	current = (*list)->next;
	while (current != NULL)
	{
		temp = current->prev;
		while (temp != NULL && temp->n > current->n)
		{
			/* Swap current node with its previous node */
			if (temp->prev != NULL)
				    temp->prev->next = current;
			current->prev = temp->prev;
			temp->prev = current;
			temp->next = current->next;
			if (current->next != NULL)
				    current->next->prev = temp;
			current->next = temp;

			/* Update list pointer if necessary */
			if (current->prev == NULL)
				    *list = current;

			/* Print list after each swap */
			print_list(*list);

			temp = current->prev;
		}
		current = current->next;
	}
}

