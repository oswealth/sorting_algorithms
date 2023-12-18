#include "deck.h"

int compare_strings(const char *s1, const char *s2);
char card_value(deck_node_t *card);
void sort_deck_by_suit(deck_node_t **deck);
void sort_deck_by_rank(deck_node_t **deck);
void sort_deck(deck_node_t **deck);

/**
 *compare_strings - Compares two strings.
 * @s1: The first string to be compared.
 * @s2: The second string to be compared.
 *
 * Return: Positive byte difference if s1 > s2
 *         0 if s1 == s2
 *         Negative byte difference if s1 < s2
 */
int compare_strings(const char *s1, const char *s2)
{
	while (*s1 && *s2 && *s1 == *s2)
	{
		s1++;
		s2++;
	}

	if (*s1 != *s2)
		return (*s1 - *s2);
	return (0);
}

/**
 * card_value - Get the numerical value of a card.
 * @card: A pointer to a deck_node_t card.
 *
 * Return: The numerical value of the card.
 */

char card_value(deck_node_t *card)
{
	int value = atoi(card->card->value);

	switch (value)
	{
		case 0:
			return (0);
		case 1:
			return (1);
		case 2:
			return (2);
		case 3:
			return (3);
		case 4:
			return (4);
		case 5:
			return (5);
		case 6:
			return (6);
		case 7:
			return (7);
		case 8:
			return (8);
		case 9:
			return (9);
		case 10:
			return (10);
		default: /* if card value is not a number */
			if (compare_strings(card->card->value, "Jack") == 0)
				return (11);
			if (compare_strings(card->card->value, "Queen") == 0)
				return (12);
			return (13); /* otherwise */
	}
}


/**
 * sort_deck_by_suit - Sort a deck of cards from spades to diamonds.
 * @deck: A pointer to the head of a deck_node_t doubly-linked list.
 */
void sort_deck_by_suit(deck_node_t **deck)
{
	deck_node_t *iter, *insert, *tmp;

	for (iter = (*deck)->next; iter != NULL; iter = tmp)
	{
		tmp = iter->next;
		insert = iter->prev;
		do {
			if (insert == NULL)
				break;
			insert->next = iter->next;
			if (iter->next != NULL)
				iter->next->prev = insert;
			iter->prev = insert->prev;
			iter->next = insert;
			if (insert->prev != NULL)
				insert->prev->next = iter;
			else
				*deck = iter;
			insert->prev = iter;
			insert = iter->prev;
		} while (insert->card->kind > iter->card->kind);
	}
}


/**
 * sort_deck_by_rank - Sort a deck of cards sorted from
 *                             spades to diamonds from ace to king.
 * @deck: A pointer to the head of a deck_node_t doubly-linked list.
 */
void sort_deck_by_rank(deck_node_t **deck)
{
	deck_node_t *iter, *insert, *tmp;

	for (iter = (*deck)->next; iter != NULL; iter = tmp)
	{
		tmp = iter->next;
		insert = iter->prev;
		while (insert != NULL &&
		       insert->card->kind == iter->card->kind &&
		       card_value(insert) > card_value(iter))
		{
			insert->next = iter->next;
			if (iter->next != NULL)
				iter->next->prev = insert;
			iter->prev = insert->prev;
			iter->next = insert;
			if (insert->prev != NULL)
				insert->prev->next = iter;
			else
				*deck = iter;
			insert->prev = iter;
			insert = iter->prev;
		}
	}
}

/**
 * sort_deck - Sort a deck of cards from ace to king and
 *             from spades to diamonds.
 * @deck: A pointer to the head of a deck_node_t doubly-linked list.
 */
void sort_deck(deck_node_t **deck)
{
	if (deck == NULL || *deck == NULL || (*deck)->next == NULL)
		return;

	sort_deck_by_suit(deck);
	sort_deck_by_rank(deck);
}
