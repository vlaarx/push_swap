#include "libft.h"

char	*ft_strncat(char *s1, const char *s2, size_t n)
{
	size_t	i;
	size_t	l;

	i = 0;
	l = 0;
	while (s1[i])
		i++;
	while (l < n && s2[l])
	{
		s1[i] = s2[l];
		l++;
		i++;
	}
	s1[i] = '\0';
	return (s1);
}
