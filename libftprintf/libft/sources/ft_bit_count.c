#include "libft.h"

int			ft_bit_count(unsigned int sym)
{
	int		i;
	int		j;

	i = 0;
	j = 32;
	while (j-- && !((sym >> j) & 1))
		i++;
	return (32 - i);
}
