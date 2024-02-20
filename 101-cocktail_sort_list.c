#include "sort.h"

/**
 * swap_nodes - Swaps two nodes in a doubly linked list
 * @list: Double pointer to the head of the list
 * @a: Pointer to the first node
 * @b: Pointer to the second node
 */
void swap_nodes(listint_t **list, listint_t *a, listint_t *b)
{
	if (a->prev)
		a->prev->next = b;
	else *list = b;

	if (b->next)
		b->next->prev = a;

	a->next = b->next;
	b->prev = a->prev;
	a->prev = b;
	b->next = a;
}

/**
 * cocktail_sort_list - Sorts a doubly linked list of integers,
 *  in ascending order using Cocktail shaker sort
 * @list: Double pointer to the head of the list
 */
void cocktail_sort_list(listint_t **list)
{
	int swapped;
	listint_t *start = NULL;
	listint_t *end = NULL;

	if (list == NULL || *list == NULL || (*list)->next == NULL)
		return;

	do {
		swapped = 0;
		for (listint_t *current = start; current && current->next != end;
			current = current->next)
		{
			if (current->n > current->next->n)
			{
				swap_nodes(list, current, current->next);
				print_list(*list);
				swapped = 1;
			}
		}

		end = end ? end->prev : *list;
		if (swapped == 0)
			break;
		swapped = 0;
		for (listint_t *current = end; current && current->prev != start;
			current = current->prev)
		{
			if (current->prev && current->n < current->prev->n)
			{
				swap_nodes(list, current->prev, current);
				print_list(*list);
				swapped = 1;
			}
		}

		start = start ? start->next : *list;
	} while (swapped);
}
