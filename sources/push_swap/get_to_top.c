/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_to_top.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: screight <screight@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/08/19 12:20:06 by screight          #+#    #+#             */
/*   Updated: 2019/08/28 19:19:44 by screight         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void		get_min_to_top(t_pswp **form, int ind, int i, int j)
{
	t_stack	*a;

	i = (ind == 0) ? find_first((*form)->a, 0, 1) : (*form)->amnt;
	if (i == (*form)->amnt)
	{
		a = (*form)->a;
		while (a)
		{
			i = (a->index < i) ? a->index : i;
			a = a->next;
		}
		i = find_first((*form)->a, i, i + 1);
	}
	j = count_stack((*form)->a) - i;
	if (i <= j)
	{
		while (i--)
			rotate(&(*form)->a, &(*form)->af, 1, 1);
	}
	else
	{
		while (j--)
			rev_rotate(&(*form)->a, &(*form)->af, 1, 1);
	}
}

void		get_to_top2_1(t_pswp **form, int rop)
{
	if (rop == RA)
		rotate(&(*form)->a, &(*form)->af, 1, 1);
	else if (rop == RB)
		rotate(&(*form)->b, &(*form)->bf, 1, 0);
	else if (rop == RRA)
		rev_rotate(&(*form)->a, &(*form)->af, 1, 1);
	else if (rop == RRB)
		rev_rotate(&(*form)->b, &(*form)->bf, 1, 0);
}

void		get_to_top2(t_pswp **form, t_opns *op, int s, int ss)
{
	int		rop;

	if (!(op->rot))
	{
		rop = (op->adir <= op->bdir) ? RRB : RRA;
		while (ss-- > 0)
		{
			rev_rotate(&(*form)->a, &(*form)->af, 0, 1);
			rev_rotate(&(*form)->b, &(*form)->bf, 2, 0);
		}
	}
	else
	{
		rop = (op->adir <= op->bdir) ? RB : RA;
		while (ss-- > 0)
		{
			rotate(&(*form)->a, &(*form)->af, 0, 1);
			rotate(&(*form)->b, &(*form)->bf, 2, 0);
		}
	}
	while (s-- > 0)
		get_to_top2_1(form, rop);
}

void		get_to_top1(t_pswp **form, int r, int rr, char ch)
{
	while (r-- > 0)
	{
		if (ch == 'a')
			rotate(&(*form)->a, &(*form)->af, 1, 1);
		else
			rotate(&(*form)->b, &(*form)->bf, 1, 0);
	}
	while (rr-- > 0)
	{
		if (ch == 'a')
			rev_rotate(&(*form)->b, &(*form)->bf, 1, 0);
		else
			rev_rotate(&(*form)->a, &(*form)->af, 1, 1);
	}
}
