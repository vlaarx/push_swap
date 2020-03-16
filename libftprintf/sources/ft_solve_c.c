#include "libftprintf.h"

int					ft_solve_c(t_spec *argument, va_list arg)
{
	long			sym;
	int				w;
	int				valid;
	int				count;

	count = 1;
	sym = va_arg(arg, int);
	if (!(valid = ft_valid_flags_c_s_p(argument)))
		return (0);
	if ((argument->size && argument->size[0] == 'l') || argument->type == 'C')
	{
		if ((sym >= 55296 && sym <= 57343) || sym >= 1114111 || sym < 0)
			return (-1);
		return (valid == -1) ? ft_write_utf(argument, sym, 1)
		: ft_write_utf(argument, sym, 0);
	}
	w = argument->width - 1;
	while (valid == 1 && --w >= 0 && count++)
		(argument->flags && argument->flags[0] == '0') ? write(1, "0", 1)
			: write(1, " ", 1);
	write(1, &sym, 1);
	while (valid != 1 && --w >= 0 && count++)
		write(1, " ", 1);
	return (count);
}
