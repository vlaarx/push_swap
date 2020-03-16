#include "libft.h"

int		ft_count_digits(char *number)
{
	int	i;
	int	len;

	i = 0;
	len = 0;
	if (number[i] == '-')
		i++;
	while (number[i])
	{
		len++;
		i++;
	}
	return (len);
}
