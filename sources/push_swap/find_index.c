/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   find_index.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: screight <screight@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/08/18 14:31:09 by screight          #+#    #+#             */
/*   Updated: 2019/08/28 19:16:42 by screight         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int			find_place(t_pswp *form, int index)
{
	t_stack	*a;
	int		i;

	if (form->a->index > index && form->af->index < index)
		return (0);
	i = 1;
	a = form->a;
	while (a->next)
	{
		if (a->index < index && a->next->index > index)
			break ;
		i++;
		a = a->next;
	}
	return (i);
}

int			find_first(t_stack *tmp, int st, int end)
{
	int		i;

	i = 0;
	while (tmp)
	{
		if (tmp->index >= st && tmp->index < end)
			return (i);
		tmp = tmp->next;
		i++;
	}
	return (-1);
}

int			find_last(t_stack *tmp, int st, int end)
{
	int		i;
	int		ret;

	i = 0;
	ret = -1;
	while (tmp)
	{
		if (tmp->index >= st && tmp->index < end)
			ret = i;
		tmp = tmp->next;
		i++;
	}
	return (ret);
}
