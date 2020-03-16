#include "libftprintf.h"

int		ft_valid_flags_c_s_p(t_spec *argument)
{
	if (!argument->flags)
		return (1);
	else if (argument->type == 'c' && !(argument->flags[0] == '-'))
		return (1);
	else if (argument->flags[0] == '-' || argument->flags[0] == '0')
		return (argument->flags[0] == '-') ? -1 : 2;
	return (0);
}
