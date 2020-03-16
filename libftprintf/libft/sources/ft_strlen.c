#include "libft.h"

size_t	ft_strlen(const char *s)
{
	int		i;

	i = 0;
	while (*s != '\0')
	{
		s++;
		i++;
	}
	return (i);
}
