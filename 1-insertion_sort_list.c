#include "sort.h"

/**
 * insertion_sort_list - sorts a doubly linked list of integers
 * in ascending order using the Insertion sort algorithm
 * @list: list to sort
 * listint_t - list of integers
 */

void insertion_sort_list(listint_t **list)
{
	listint_t *current, *key, *previous;

	if (list == NULL || *list == NULL || (*list)->next == NULL)
		return;

	current = *list;
	while (current)
	{
		key = current->next;
		while (current->prev && current->n < current->prev->n)
		{
			previous = current->prev;
			previous->next = current->next;
			if (current->next)
				current->next->prev = previous;
			current->next = previous;
			current->prev = previous->prev;
			previous->prev = current;
			if (current->prev)
				current->prev->next = current;
			else
				*list = current;
			print_list(*list);
		}
		current = key;
	}
}
