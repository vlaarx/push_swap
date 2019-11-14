/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_count_digits.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: screight <screight@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/07/17 16:21:29 by egiant            #+#    #+#             */
/*   Updated: 2019/08/28 20:28:40 by screight         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int		ft_count_digits(char *number)
{
	int	i;
	int	len;

	i = 0;
	len = 0;
	if (number[i] == '-')
		i++;
	while (number[i])
	{
		len++;
		i++;
	}
	return (len);
}
