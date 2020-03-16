#include "libft.h"

void	ft_putstr(char const *s)
{
	if (!s)
		return ;
	while (*s != '\0')
	{
		ft_putchar(*s);
		s++;
	}
}
