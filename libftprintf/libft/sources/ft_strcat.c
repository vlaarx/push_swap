#include "libft.h"

char	*ft_strcat(char *s1, const char *s2)
{
	size_t	i;
	size_t	n;

	i = 0;
	n = 0;
	while (s1[i])
		i++;
	while (s2[n])
	{
		s1[i] = s2[n];
		n++;
		i++;
	}
	s1[i] = '\0';
	return (s1);
}
