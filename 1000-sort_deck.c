#include "deck.h"

/**
 *_strcmp - compare two strings
 *@str1: string
 *@str2: string
 *Return: 1 str1 and str2 is equal, 0 they are not equal
 */
int _strcmp(const char *str1, char *str2)
{
	size_t i = 0;

	if (str1 == NULL)
		return (0);
	while (str1[i])
	{
		if (str1[i] != str2[i])
			return (0);
		i++;
	}
	if (str1[i] == '\0' && str2[i])
		return (0);
	return (1);
}
/**
 * get_card_position - return the position based on card you put in
 * @node: represent the card
 * Return: return the card position
 */
int get_card_position(deck_node_t *node)
{
	int position;

	position = (*node).card->value[0] - '0';
	if (position < 50 || position > 57)
	{
		if (_strcmp((*node).card->value, "Ace") == 1)
			position = 1;
		else if (_strcmp((*node).card->value, "10") == 1)
			position = 10;
		else if (_strcmp((*node).card->value, "Jack") == 1)
			position = 11;
		else if (_strcmp((*node).card->value, "Queen") == 1)
			position = 12;
		else if (_strcmp((*node).card->value, "King") == 1)
			position = 13;
	}
	position += (*node).card->kind * 13;
	return (position);
}
/**
 *swap_card - swap a card for his previous one
 *@card: card
 *@deck: card deck
 *Return: return a pointer to a card which was enter it
 */
deck_node_t *swap_card(deck_node_t *card, deck_node_t **deck)
{
	deck_node_t *back = card->prev, *current = card;

	back->next = current->next;
	if (current->next)
		current->next->prev = back;
	current->next = back;
	current->prev = back->prev;
	back->prev = current;
	if (current->prev)
		current->prev->next = current;
	else
		*deck = current;
	return (current);
}

/**
 * insertion_sort_deck - function that sorts a doubly linked deck
 * of integers in ascending order using the Insertion sort algorithm
 * @deck: Dobule linked deck to sort
 */
void insertion_sort_deck(deck_node_t **deck)
{
	int prev_position, current_position;
	deck_node_t *node;

	if (deck == NULL || (*deck)->next == NULL)
		return;
	node = (*deck)->next;
	while (node)
	{
		/* preparing the previous value */
		if (node->prev)
		{
			prev_position = get_card_position((node->prev));
			current_position = get_card_position(node);
		}
		while ((node->prev) && (prev_position > current_position))
		{
			prev_position = get_card_position((node->prev));
			current_position = get_card_position(node);
			node = swap_card(node, deck);

		}
		node = node->next;
	}
}
/**
 * sort_deck - sort a deck you put in using
 * insertion sort algorithm
 * @deck: deck
 */
void sort_deck(deck_node_t **deck)
{
	insertion_sort_deck(deck);
}
