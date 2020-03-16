#include "libftprintf.h"

int			ft_valid_flags(t_spec *arg, int i)
{
	int		count;
	char	*newflags;
	char	*ptr;
	int		ef;

	ef = 0;
	if (!arg->flags)
		return (1);
	ft_ignored_zero(arg);
	ft_ignored_space(arg);
	if (!(count = ft_count_valid(arg, arg->type, &ef)))
		ft_strdel(&(arg->flags));
	else if (count > 0)
	{
		if (!(newflags = (char*)malloc(sizeof(char) * (count + 1))))
			return (0);
		newflags[count--] = '\0';
		while (count >= 0)
			(arg->flags[i] != 'x') ? newflags[count--] = arg->flags[i++] : i++;
		ptr = arg->flags;
		arg->flags = newflags;
		free(ptr);
	}
	return (ef == -1) ? -1 : 1;
}
