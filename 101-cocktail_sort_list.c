#include "sort.h"

/**
 * cocktail_sort_list - sorts a doubly linked list of integers
 * in ascending order using the Cocktail shaker sort algorithm
 * listint_t - doubly linked list
 * @list: list to sort
 */

void cocktail_sort_list(listint_t **list)
{
	listint_t *current, *temp;
	int swapped = 1;

	if (list == NULL || *list == NULL || (*list)->next == NULL)
		return;

	current = *list;
	while (swapped)
	{
		swapped = 0;
		while (current->next != NULL)
		{
			if (current->n > current->next->n)
			{
				temp = current->next;
				swap_nodes(current, temp, list);
				swapped = 1;
			}
			else
				current = current->next;
		}

		if (swapped == 0)
			break;
		swapped = 0;
		while (current->prev != NULL)
		{
			if (current->n < current->prev->n)
			{
				temp = current->prev;
				swap_nodes(temp, current, list);
				swapped = 1;
			}
			else
				current = current->prev;
		}
	}	
}

/**
 * swap_nodes - swaps two nodes in a doubly linked list
 * listint_t - doubly linked list
 * @node1: first node
 * @node2: second node
 * @list: list to sort
 */

void swap_nodes(listint_t *node1, listint_t *node2, listint_t **list)
{
	if (node1->prev != NULL)
		node1->prev->next = node2;
	if (node2->next != NULL)
		node2->next->prev = node1;
	node1->next = node2->next;
	node2->prev = node1->prev;
	node1->prev = node2;
	node2->next = node1;
	if (node2->prev == NULL)
		*list = node2;
	print_list(*list);
}
