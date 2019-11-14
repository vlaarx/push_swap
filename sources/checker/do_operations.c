/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   do_operations.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: screight <screight@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/08/28 16:34:42 by screight          #+#    #+#             */
/*   Updated: 2019/08/28 21:22:46 by screight         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	do_more_ops(t_pswp **form, t_oplst *list)
{
	if (list->op == PB)
	{
		push(&(*form)->a, &(*form)->b, (*form)->v, 0);
		if (!(*form)->a || !(*form)->a->next)
			(*form)->af = (*form)->a;
		if (!(*form)->b->next)
			(*form)->bf = (*form)->b;
	}
	else if (list->op == RR)
	{
		rotate(&(*form)->a, &(*form)->af, 0, 0);
		(*form)->v ? rotate(&(*form)->b, &(*form)->bf, 2, 0) :
										rotate(&(*form)->b, &(*form)->bf, 0, 0);
	}
	else if (list->op == RRA)
		rev_rotate(&(*form)->a, &(*form)->af, (*form)->v, 1);
	else if (list->op == RRB)
		rev_rotate(&(*form)->b, &(*form)->bf, (*form)->v, 0);
	else if (list->op == RRR)
	{
		rev_rotate(&(*form)->a, &(*form)->af, 0, 0);
		(*form)->v ? rev_rotate(&(*form)->b, &(*form)->bf, 2, 0) :
									rev_rotate(&(*form)->b, &(*form)->bf, 0, 0);
	}
}

void	do_ops(t_pswp **form, t_oplst *list)
{
	if (list->op == SA)
		swap((*form)->a, (*form)->v, 1);
	else if (list->op == SB)
		swap((*form)->b, (*form)->v, 0);
	else if (list->op == SS)
	{
		swap((*form)->a, 0, 0);
		(*form)->v ? swap((*form)->b, 2, 0) : swap((*form)->b, 0, 0);
	}
	else if (list->op == RA)
		rotate(&(*form)->a, &(*form)->af, (*form)->v, 1);
	else if (list->op == RB)
		rotate(&(*form)->b, &(*form)->bf, (*form)->v, 0);
	else if (list->op == PA)
	{
		push(&(*form)->b, &(*form)->a, (*form)->v, 1);
		if (!(*form)->b || !(*form)->b->next)
			(*form)->bf = (*form)->b;
		if (!(*form)->a->next)
			(*form)->af = (*form)->a;
	}
	else
		do_more_ops(form, list);
}

void	do_operations(t_pswp **f)
{
	t_oplst		*list;
	int			i;
	int			a;

	a = (*f)->amnt;
	i = 0;
	list = (*f)->lst;
	if ((*f)->v)
	{
		ft_printf("\x1b[2J");
		visualise(*f, 1, a - count_stack((*f)->a), a - count_stack((*f)->b));
		usleep(1500000);
	}
	while (list && ++i)
	{
		if ((*f)->v)
			visualise(*f, 0, a - count_stack((*f)->a),
													a - count_stack((*f)->b));
		if ((*f)->v && i == 1)
			ft_printf("\n");
		do_ops(f, list);
		list = list->next;
	}
	if ((*f)->v)
		visualise(*f, 0, a - count_stack((*f)->a), a - count_stack((*f)->b));
}
