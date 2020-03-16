#include "push_swap.h"

void		clean_str(char **str)
{
	int	i;

	i = 0;
	while (str[i])
		free(str[i++]);
	free(str);
}

int			check_dublicates(t_stack *start, t_stack *end)
{
	t_stack	*tmp;

	tmp = start->next;
	while (start)
	{
		while (tmp)
		{
			if (start && tmp && start->value == tmp->value)
				return (0);
			tmp = tmp->next;
		}
		start = start->next;
		if (start && start != end)
			tmp = start->next;
		else
			break ;
	}
	return (1);
}

int			help(char **s, int i, int j)
{
	while (s[j])
	{
		if ((s[j][++i] < '0' && s[j][i] != '-' && s[j][i] != '+') ||
			s[j][i] > '9')
			return (0);
		while (s[j][++i])
		{
			if ((s[j][i] < '0' || s[j][i] > '9') && s[j][i] != ' ')
				return (0);
		}
		i = -1;
		j++;
	}
	return (1);
}

int			validate_input(t_pswp **form, char **av, int l, int j)
{
	char	**str;
	int		k;

	while (av[++j] && j >= 0)
	{
		str = ft_strsplit(av[j], ' ');
		if (!help(str, -1, 0))
			return (-1);
		k = -1;
		while (str[++k])
		{
			if (k == 0 && j == l && !((*form)->af = make_stack(str[k], 1)))
				return (-1);
			else if (((j == l && k > 0) || j != l) &&
								!((*form)->af->next = make_stack(str[k], 1)))
				return (-1);
			(*form)->a = (k == 0 && j == l) ? (*form)->af : (*form)->a;
			(*form)->af = (k == 0 && j == l) ? (*form)->af : (*form)->af->next;
		}
		clean_str(str);
		(*form)->amnt += k;
	}
	if ((*form)->a->next && !(check_dublicates((*form)->a, (*form)->af)))
		return (-1);
	return (1);
}
