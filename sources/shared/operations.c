/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   operations.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: screight <screight@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/08/12 11:49:53 by screight          #+#    #+#             */
/*   Updated: 2019/08/28 21:15:45 by screight         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void		swap(t_stack *stack, int pr, int s)
{
	int		val;
	int		i;

	if (!stack || !stack->next)
	{
		if (pr == 1)
			s ? ft_printf("sa\n") : ft_printf("sb\n");
		else if (pr == 2)
			ft_printf("ss\n");
		return ;
	}
	val = stack->value;
	i = stack->index;
	stack->value = stack->next->value;
	stack->index = stack->next->index;
	stack->next->value = val;
	stack->next->index = i;
	if (pr == 1)
		s ? ft_printf("sa\n") : ft_printf("sb\n");
	else if (pr == 2)
		ft_printf("ss\n");
}

void		push(t_stack **s1, t_stack **s2, int pr, int s)
{
	t_stack	*tmp;

	if (!*s1)
	{
		if (pr == 1)
			s ? ft_printf("pa\n") : ft_printf("pb\n");
		return ;
	}
	tmp = make_stack("0", 0);
	tmp->value = (*s1)->value;
	tmp->index = (*s1)->index;
	tmp->next = *s2;
	(*s2) = tmp;
	tmp = (*s1)->next;
	free(*s1);
	*s1 = tmp;
	if (pr == 1)
		s ? ft_printf("pa\n") : ft_printf("pb\n");
}

void		rotate(t_stack **start, t_stack **end, int pr, int s)
{
	t_stack *tmp;

	if (!*start || !*end || *start == *end)
	{
		if (pr == 1)
			s ? ft_printf("ra\n") : ft_printf("rb\n");
		else if (pr == 2)
			ft_printf("rr\n");
		return ;
	}
	tmp = (*start)->next;
	(*start)->next = NULL;
	(*end)->next = *start;
	*end = (*end)->next;
	*start = tmp;
	if (pr == 1)
		s ? ft_printf("ra\n") : ft_printf("rb\n");
	else if (pr == 2)
		ft_printf("rr\n");
}

void		rev_rotate(t_stack **start, t_stack **end, int pr, int s)
{
	t_stack *tmp;

	if (!*start || !*end || *start == *end)
	{
		if (pr == 1)
			s ? ft_printf("rra\n") : ft_printf("rrb\n");
		else if (pr == 2)
			ft_printf("rrr\n");
		return ;
	}
	tmp = (*start);
	while (tmp->next != *end)
		tmp = tmp->next;
	tmp->next = NULL;
	(*end)->next = (*start);
	*start = *end;
	*end = tmp;
	if (pr == 1)
		s ? ft_printf("rra\n") : ft_printf("rrb\n");
	else if (pr == 2)
		ft_printf("rrr\n");
}
