#include "libftprintf.h"

int			ft_write_ox_case2(t_spec *argument, char *number, int dig, int reg)
{
	int		i;
	int		difference;

	i = 0;
	difference = argument->precision - dig;
	if (argument->type != 'o' && argument->type != 'O')
	{
		if (argument->flags && (argument->flags[1]
			|| argument->flags[0] == '#') && number[0] != '0')
		{
			(reg == 0) ? write(1, "0x", 2) : write(1, "0X", 2);
			i = 2;
		}
	}
	while (difference-- > 0)
		write(1, "0", 1);
	while (*number)
		write(1, number++, 1);
	return (argument->precision + i);
}
