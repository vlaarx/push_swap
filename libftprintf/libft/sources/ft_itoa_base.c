/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_itoa_base.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: screight <screight@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/08/07 21:43:33 by screight          #+#    #+#             */
/*   Updated: 2019/08/10 14:30:15 by screight         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int			ft_nbr_len(int nb, int base)
{
	int		i;

	i = 0;
	while (nb)
	{
		nb /= base;
		i++;
	}
	return (i);
}

char		*ft_itoa_base(int value, int base)
{
	int		neg;
	int		len;
	char	*s_base;
	char	*result;

	len = 0;
	s_base = "0123456789ABCDEF";
	if (value == 0)
		return ("0");
	if (base == 10 && value == -2147483648)
		return ("-2147483648");
	neg = (value < 0) ? 1 : 0;
	value = (value < 0) ? -value : value;
	len = ft_nbr_len(value, base) + neg;
	if (!(result = (char *)malloc(sizeof(char) * (len + 1))))
		return (NULL);
	result[len--] = '\0';
	result[len--] = s_base[value % base];
	while (value /= base)
		result[len--] = s_base[value % base];
	if (neg == 1)
		result[len] = '-';
	return (result);
}
