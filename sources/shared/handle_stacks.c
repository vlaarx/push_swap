#include "push_swap.h"

void		clean_stack(t_stack **top)
{
	t_stack *tmp;

	while (*top)
	{
		tmp = (*top)->next;
		free(*top);
		*top = tmp;
	}
	*top = NULL;
}

int			count_stack(t_stack *stack)
{
	int		i;

	i = 0;
	while (stack)
	{
		i++;
		stack = stack->next;
	}
	return (i);
}

void		index_stack(t_stack *s, int amount)
{
	t_stack	*tmp;
	int		i;
	int		min;

	i = -1;
	while (++i < amount)
	{
		tmp = s;
		while (tmp->index != -1)
			tmp = tmp->next;
		min = tmp->value;
		while (tmp)
		{
			if (tmp->value < min && tmp->index == -1)
				min = tmp->value;
			tmp = tmp->next;
		}
		tmp = s;
		while (tmp->value != min)
			tmp = tmp->next;
		tmp->index = i;
	}
}

t_stack		*make_stack(char *s_value, int tr)
{
	t_stack	*new;

	if (!(new = (t_stack *)malloc(sizeof(t_stack))))
		return (NULL);
	new->next = NULL;
	new->index = -1;
	if (s_value && tr == 1)
	{
		new->value = ft_atol(s_value);
		if ((new->value == -1 && s_value[0] != '-' && s_value[1] != '1' &&
			s_value[2] != '\0') || (new->value == 0 && s_value[0] != '0' &&
			s_value[1] != '0') || new->value > INT_MAX || new->value < INT_MIN)
			return (NULL);
	}
	return (new);
}
