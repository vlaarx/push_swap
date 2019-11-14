/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   minialg.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: screight <screight@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/08/28 13:50:31 by screight          #+#    #+#             */
/*   Updated: 2019/08/28 19:20:09 by screight         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void		sort_three(t_pswp **form)
{
	if ((*form)->a->index > (*form)->a->next->index &&
						(*form)->a->index > (*form)->af->index &&
							(*form)->a->next->index < (*form)->af->index)
		rotate(&(*form)->a, &(*form)->af, 1, 1);
	else if ((*form)->a->index > (*form)->a->next->index &&
				(*form)->a->next->index > (*form)->a->next->next->index)
	{
		rotate(&(*form)->a, &(*form)->af, 1, 1);
		swap((*form)->a, 1, 1);
	}
	else if ((*form)->a->index < (*form)->a->next->index &&
									(*form)->a->index > (*form)->af->index)
		rev_rotate(&(*form)->a, &(*form)->af, 1, 1);
	else
	{
		if ((*form)->a->index > (*form)->a->next->index)
			swap((*form)->a, 1, 1);
		if ((*form)->a->next->index > (*form)->a->next->next->index)
		{
			rotate(&(*form)->a, &(*form)->af, 1, 1);
			swap((*form)->a, 1, 1);
		}
		get_min_to_top(form, -1, 0, 0);
	}
}

void		sort_four_five(t_pswp **form)
{
	sort_three(form);
	if ((*form)->b->next && ((*form)->b->index == 0 ||
		(*form)->bf->index == 0 || (*form)->b->index == (*form)->amnt - 1 ||
									(*form)->bf->index == (*form)->amnt - 1))
	{
		if ((*form)->b->index == 0 || (*form)->bf->index == 0)
		{
			if ((*form)->b->index > (*form)->bf->index)
				swap((*form)->b, 1, 0);
		}
		else if ((*form)->b->index < (*form)->bf->index)
			swap((*form)->b, 1, 0);
		push(&(*form)->b, &(*form)->a, 1, 1);
		if ((*form)->b && (*form)->b->index == (*form)->amnt - 1)
			push(&(*form)->b, &(*form)->a, 1, 1);
		if ((*form)->b)
			do_sort(form);
	}
	else
	{
		while ((*form)->b)
			do_sort(form);
	}
	get_min_to_top(form, 0, 0, 0);
}

int			minialg(t_pswp **form)
{
	if ((*form)->amnt == 2)
		swap((*form)->a, 1, 1);
	else if ((*form)->amnt == 3)
		sort_three(form);
	else if ((*form)->amnt < 6)
	{
		while (count_stack((*form)->a) != 3)
			push(&(*form)->a, &(*form)->b, 1, 0);
		(*form)->bf = ((*form)->b->next) ? (*form)->b->next : (*form)->b;
		sort_four_five(form);
	}
	else
	{
		while (count_stack((*form)->a) != 2)
		{
			if ((*form)->a->index == 0)
				rotate(&(*form)->a, &(*form)->af, 1, 1);
			if ((*form)->a->index == (*form)->amnt - 1)
				rotate(&(*form)->a, &(*form)->af, 1, 1);
			push(&(*form)->a, &(*form)->b, 1, 0);
		}
		do_sort(form);
		get_min_to_top(form, 0, 0, 0);
	}
	return (0);
}
