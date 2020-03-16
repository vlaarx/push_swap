#include "libftprintf.h"

int			ft_edit_flags(t_spec *argument, char ch)
{
	int		n;
	int		i;
	char	*result;
	char	*swap;

	n = 1;
	i = 0;
	while (argument->flags && (argument->flags)[i])
	{
		if ((argument->flags)[i] == ch)
			return (1);
		i++;
	}
	result = (char *)malloc(sizeof(char) * (n + i + 1));
	n = 0;
	result[n++] = ch;
	while (--i >= 0)
		result[n++] = (argument->flags)[i];
	result[n] = '\0';
	swap = argument->flags;
	argument->flags = result;
	ft_strdel(&swap);
	argument->precision = 0;
	return (1);
}
