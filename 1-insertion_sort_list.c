#include "sort.h"

/**
 * insertion_sort_list -a function that sorts a doubly linked list of integers
 * in ascending order using an insertion sort algorithm
 * @list: list
 */
void insertion_sort_list(listint_t **list)
{
	listint_t *ld, *fllw, *new, *tmp;

	if (!list || !(*list) || !((*list)->next))
		return;

	fllw = (*list);
	ld = (*list)->next;
	while (ld)
	{
		new = ld->next;
		while (fllw && ld->n < fllw->n)
		{
			if (fllw->prev)
				fllw->prev->next = ld;
			else
				*list = ld;
			if (ld->next)
				ld->next->prev = fllw;
			tmp = ld->next;
			ld->next = fllw;
			ld->prev = fllw->prev;
			fllw->next = tmp;
			fllw->prev = ld;
			print_list(*list);
			fllw = ld->prev;
		}
		ld = new;
		if (ld)
			fllw = ld->prev;
	}
}
