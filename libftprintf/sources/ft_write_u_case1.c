#include "libftprintf.h"

int			ft_write_u_case1(t_spec *argument, char *number, int digits)
{
	int		difference;

	difference = argument->precision - digits;
	while (difference-- > 0)
		write(1, "0", 1);
	while (*number != '\0')
		write(1, number++, 1);
	return (argument->precision >= digits) ? argument->precision : digits;
}
