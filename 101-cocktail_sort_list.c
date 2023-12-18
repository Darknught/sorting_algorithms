#include "sort.h"

/**
 * swap_n - Swaps two nodes in a doubly linked list
 * @list: Pointer to the head of the linked list
 * @node1: first node
 * @node2: second node
 */
void swap_n(listint_t **list, listint_t *node1, listint_t *node2)
{
	listint_t *temp_prev, *temp_next;

	if (node1 == NULL || node2 == NULL)
		return;

	if (node1->prev != NULL)
		node1->prev->next = node2;
	if (node2->next != NULL)
		node2->next->prev = node1;

	if (node1->next != NULL && node1->next != node2)
		node1->next->prev = node2;
	if (node2->prev != NULL && node2->prev != node1)
		node2->prev->next = node1;
	temp_prev = node1->prev;
	temp_next = node1->next;

	node1->prev = node2->prev;
	node1->next = node2->next;

	node2->prev = temp_prev;
	node2->next = temp_next;

	if (node1->prev == NULL)
		*list = node2;

	if (node2->next == NULL)
		*list = node1;
}

/**
 * cocktail_sort_list - Sort a dobly linked list using the Cocktail Shaker sort
 * @list: Pointer to the head of the linked list
 *
 */
void cocktail_sort_list(listint_t **list)
{
	int value;
	listint_t *current;

	if (list == NULL || *list == NULL || (*list)->next == NULL)
		return;

	do {
		value = 0;
		for (current = *list; current->next != NULL;
				current = current->next)
		{
			if (current->n > current->next->n)
			{
				swap_n(list, current, current->next);
				print_list(*list);
				value = 1;
			}
		}
		if (!value)
			break;

		value = 0;
		for (current = current->prev; current != NULL; current = current->prev)
		{
			if (current->prev != NULL && current->prev->n > current->n)
			{
				swap_n(list, current->prev, current);
				print_list(*list);
				value = 1;
			}
		}
	} while (value);
}
