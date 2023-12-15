#include "sort.h"

void insertion_sort_list(listint_t **list);

/**
 * insertion_sort_list - Function that sorts a doubly linked list in asc order
 * @list: list to sort
 *
 */
void insertion_sort_list(listint_t **list)
{
	listint_t *sorted, *temp, *current;

	if (list == NULL || *list == NULL || (*list)->next == NULL)
	{
		return;
	}

	sorted = NULL;

	while (*list != NULL)
	{
		current = *list;
		*list = current->next;

		if (sorted == NULL || current->n <= sorted->n)
		{
			current->next = sorted;
			current->prev = NULL;
			if (sorted != NULL)
			{
				sorted->prev = current;
			}
			sorted = current;
		}
		else
		{
			temp = sorted;
			while (temp->next != NULL && temp->next->n
					< current->n)
			{
				temp = temp->next;
			}
			current->next = temp->next;
			if (temp->next != NULL)
			{
				temp->next->prev = current;
			}
			current->prev = temp;
			temp->next = current;
		}
	}
	*list = sorted;
}
