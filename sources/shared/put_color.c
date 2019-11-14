/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   put_color.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: screight <screight@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/08/28 18:22:54 by screight          #+#    #+#             */
/*   Updated: 2019/08/28 21:24:14 by screight         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	put_greeting(int color)
{
	if (color)
		ft_printf("\x1b[1;34;40m");
	ft_printf("Starting ...\x1b[0m\n");
}

void	put_color(int amnt, int i, int text)
{
	if (text == 1)
		ft_printf("\x1b[1;36;40m");
	else if (text == 2)
		ft_printf("\x1b[1;35;40m");
	else
	{
		if (i <= amnt / 3)
			ft_printf("\x1b[1;36;40m");
		else if (i >= (amnt / 3) * 2)
			ft_printf("\x1b[1;35;40m");
		else
			ft_printf("\x1b[1;34;40m");
	}
}
