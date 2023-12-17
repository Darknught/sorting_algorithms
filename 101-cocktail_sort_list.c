#include "sort.h"

/**
 * swap - Swaps two nodes in a doubly linked list
 * @list: Pointer to the head of the linked list
 * @node1: first node
 * @node2: second node
 */
void swap_n(listint_t **list, listint_t *node1, listint_t *node2)
{
	if (node1->prev)
		node1->prev->next = node2;
	else
		*list = node2;

	if (node2->next)
		node2->next->prev = node1;

	node1->next = node2->next;
	node2->prev = node1->prev;
	node1->prev = node2;
	node2->next = node1;

	print_list(*list);
}

/**
 * cocktail_sort_list - Sort a dobly linked list using the Cocktail Shaker sort
 * @list: Pointer to the head of the linked list
 *
 */
void cocktail_sort_list(listint_t **list)
{
	int value = 1;
	listint_t *current;

	if (list == NULL || *list == NULL)
		return;

	while (value)
	{
		value = 0;
		for (current = *list; current->next != NULL;
				current = current->next)
		{
			if (current->n > current->next->n)
			{
				swap_n(list, current, current->next);
				value = 1;
			}
		}
		if (!value)
			break;

		value = 0;
		for(; current->prev != NULL; current = current->prev)
		{
			if (current->n < current->prev->n)
			{
				swap_n(list, current->prev, current);
				value = 1;
			}
		}
	}
}
