#include "deck.h"

/**
 * swap - swaps two nodes in a doubly linked list
 * @deck: pointer to head of list
 * @node1: first node
 * @node2: second node
 */

void swap(deck_node_t **deck, deck_node_t *node1, deck_node_t *node2)
{
	deck_node_t *tmp = NULL;

	if (node1->prev)
		node1->prev->next = node2;
	else
		*deck = node2;
	if (node2->next)
		node2->next->prev = node1;
	node1->next = node2->next;
	node2->prev = node1->prev;
	node1->prev = node2;
	node2->next = node1;

	tmp = node1;
	node1 = node2;
	node2 = tmp;
}

/**
 * sort_deck - sorts a deck of cards
 * @deck: pointer to head of list
 */

void sort_deck(deck_node_t **deck)
{
	deck_node_t *node1 = NULL, *node2 = NULL;
	int i = 0, j = 0;

	if (!deck || !(*deck) || !(*deck)->next)
		return;
	node1 = *deck;
	while (node1)
	{
		node2 = node1->next;
		while (node2)
		{
			i = 0;
			j = 0;

			while (node1->card->value[i] != '\0')
				i++;
			while (node2->card->value[j] != '\0')
				j++;
			if (i == j)
			{
				if (node1->card->kind > node2->card->kind)
					swap(deck, node1, node2);
				else if (node1->card->kind == node2->card->kind)
				{
					if (strcmp(node1->card->value, node2->card->value) > 0)
						swap(deck, node1, node2);
				}
			}
			else if (i > j)
				swap(deck, node1, node2);
			node2 = node2->next;
		}
		node1 = node1->next;
	}
}
