#include "libftprintf.h"

int		ft_write_f(t_spec *argument, char *number, int digits, int lattice)
{
	int i;

	i = 0;
	if (argument->precision == 0 && lattice != -1)
	{
		while (number[i] != '.')
			i++;
		digits--;
		number[i] = '\0';
	}
	if (digits >= argument->width)
		return (ft_write_d_case1(argument, number, digits));
	else
	{
		argument->precision = 0;
		return (ft_write_d_case2(argument, number, digits));
	}
}
