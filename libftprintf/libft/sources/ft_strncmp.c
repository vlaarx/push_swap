#include "libft.h"

int		ft_strncmp(const char *s1, const char *s2, size_t n)
{
	int		rez;
	size_t	i;

	i = 0;
	while ((*s1 != '\0' || *s2 != '\0') && i < n)
	{
		if (*s1 != *s2)
		{
			rez = (unsigned char)*s1 - (unsigned char)*s2;
			return (rez);
		}
		s1++;
		s2++;
		i++;
	}
	return (0);
}
