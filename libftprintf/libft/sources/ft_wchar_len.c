#include "libft.h"

size_t	ft_wchar_len(wchar_t *s)
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
