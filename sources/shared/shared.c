#include "push_swap.h"

int			sort_check(t_stack *tmp, int order)
{
	if (order == 1)
	{
		while (tmp && tmp->next)
		{
			if (tmp->index < tmp->next->index)
				return (0);
			tmp = tmp->next;
		}
	}
	else
	{
		while (tmp && tmp->next)
		{
			if (tmp->index > tmp->next->index)
				return (0);
			tmp = tmp->next;
		}
	}
	return (1);
}

void		clean_lst(t_oplst **lst)
{
	t_oplst *tmp;

	while (*lst)
	{
		tmp = (*lst)->next;
		free(*lst);
		(*lst) = tmp;
	}
	*lst = NULL;
}

void		clean_form(t_pswp **form)
{
	if (*form)
	{
		if ((*form)->a)
			clean_stack(&(*form)->a);
		if ((*form)->b)
			clean_stack(&(*form)->b);
		if ((*form)->lst)
			clean_lst(&(*form)->lst);
		free(*form);
		*form = NULL;
	}
}

int			display_err(t_pswp **form)
{
	if ((*form)->c)
		write(2, "\x1b[1;31m", 7);
	write(2, "Error\n\x1b[0m", 10);
	clean_form(form);
	return (-1);
}

int			initialize_form(t_pswp **form)
{
	if (!(*form = (t_pswp *)malloc(sizeof(t_pswp))))
		return (-1);
	(*form)->lst = NULL;
	(*form)->a = NULL;
	(*form)->b = NULL;
	(*form)->af = NULL;
	(*form)->bf = NULL;
	(*form)->b1 = 0;
	(*form)->b2 = 0;
	(*form)->amnt = 0;
	(*form)->v = 0;
	(*form)->c = 0;
	return (0);
}
