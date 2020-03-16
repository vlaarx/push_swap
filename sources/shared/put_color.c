#include "push_swap.h"

void	put_greeting(int color)
{
	if (color)
		ft_printf("\x1b[1;34;40m");
	ft_printf("Starting ...\x1b[0m\n");
}

void	put_color(int amnt, int i, int text)
{
	if (text == 1)
		ft_printf("\x1b[1;36;40m");
	else if (text == 2)
		ft_printf("\x1b[1;35;40m");
	else
	{
		if (i <= amnt / 3)
			ft_printf("\x1b[1;36;40m");
		else if (i >= (amnt / 3) * 2)
			ft_printf("\x1b[1;35;40m");
		else
			ft_printf("\x1b[1;34;40m");
	}
}
