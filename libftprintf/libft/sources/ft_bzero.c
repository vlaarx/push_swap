#include "libft.h"

void	ft_bzero(void *s, size_t n)
{
	if (n == 0)
		return ;
	else
	{
		while (n--)
		{
			*((unsigned char *)s) = '\0';
			s++;
		}
	}
}
