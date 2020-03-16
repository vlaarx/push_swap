#include "push_swap.h"

void	split_first(t_pswp **form)
{
	if ((*form)->a->index < (*form)->b2 && (*form)->a->index != 0)
	{
		push(&(*form)->a, &(*form)->b, 1, 0);
		if (!(*form)->bf)
			(*form)->bf = (*form)->b;
	}
	if ((*form)->a->index >= (*form)->b2 && (*form)->b &&
											(*form)->b->index <= (*form)->b1)
	{
		rotate(&(*form)->a, &(*form)->af, 0, 0);
		rotate(&(*form)->b, &(*form)->bf, 2, 0);
	}
	else if ((*form)->b && (*form)->b->index <= (*form)->b1 &&
				(*form)->b->next && (*form)->b->next->index > (*form)->b1)
		rotate(&(*form)->b, &(*form)->bf, 1, 0);
	if ((*form)->a->index >= (*form)->b2 || (*form)->a->index == 0 ||
									(*form)->a->index == (*form)->amnt - 1)
		rotate(&(*form)->a, &(*form)->af, 1, 1);
}

void	split_second(t_pswp **form)
{
	if ((*form)->a->index != (*form)->amnt - 1 && (*form)->a->index != 0)
		push(&(*form)->a, &(*form)->b, 1, 0);
	else
		rotate(&(*form)->a, &(*form)->af, 1, 1);
}

void	split_stack(t_pswp **form)
{
	t_stack		*tmp;
	int			i;

	i = find_last((*form)->a, 0, (*form)->b2);
	tmp = (*form)->a;
	while (i--)
		tmp = tmp->next;
	while ((*form)->a != tmp)
		split_first(form);
	split_first(form);
	tmp = (*form)->af;
	while ((*form)->a != tmp)
		split_second(form);
	split_second(form);
	(*form)->bf = (*form)->b;
	while ((*form)->bf->next)
		(*form)->bf = (*form)->bf->next;
}
