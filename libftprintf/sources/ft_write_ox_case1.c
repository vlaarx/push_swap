#include "libftprintf.h"

int		ft_write_ox_case1(t_spec *argument, char *number, int digits, int reg)
{
	if (argument->flags && (argument->flags[1] || argument->flags[0] == '#')
		&& *number != '0')
	{
		if (argument->type == 'o' || argument->type == 'O')
		{
			write(1, "0", 1);
			digits++;
		}
		else
		{
			(reg == 0) ? write(1, "0x", 2) : write(1, "0X", 2);
			digits += 2;
		}
	}
	while (*number)
		write(1, number++, 1);
	return (digits);
}
