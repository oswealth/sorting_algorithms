#include "sort.h"

/**
 * swap_nodes - Swap two nodes in a listint_t doubly-linked list
 *
 * @node1: The first node to swap
 * @node2: The second node to swap
 */
void swap_nodes(listint_t **head, listint_t *node1, listint_t *node2)
{
	listint_t *tmp;

	/* Check if the nodes are valid and adjacent */
	if (head == NULL || *head == NULL || node1 == NULL || node2 == NULL
			|| node1 == node2 || node1->next != node2)
		return;

	/* Swap the nodes by updating their pointers */
	tmp = node1->prev;
	node1->prev = node2;
	node1->next = node2->next;
	node2->prev = tmp;
	node2->next = node1;
	if (node1->next != NULL)
		node1->next->prev = node1;
	if (node2->prev != NULL)
		node2->prev->next = node2;

	if (*head == node1)
		*head = node2;
}


/**
 * insertion_sort_list - Sorts a doubly linked list of integers
 * in ascending order using the Insertion sort algorithm
 *
 * @list: The head of the doubly linked list
 */
void insertion_sort_list(listint_t **list)
{
	listint_t *current;

	/* Check if the list is valid */
	if (list == NULL || *list == NULL || (*list)->next == NULL)
		return;

	/* Assign the second node to current */
	current = (*list)->next;

	while (current != NULL)
	{
		while (current->prev != NULL && current->n < current->prev->n)
		{
			swap_nodes(list, current->prev, current);

			if (current->prev == NULL)
				*list = current;
			
			/* Print the list after each swap */
			print_list(*list);
		}
		current = current->next;
	}
}
