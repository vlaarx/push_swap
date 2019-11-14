/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   checker.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: screight <screight@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/08/19 12:45:28 by screight          #+#    #+#             */
/*   Updated: 2019/08/28 22:00:55 by screight         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"
#include "fcntl.h"

int			clear_line(char *line)
{
	free(line);
	line = NULL;
	return (0);
}

int			validate_operations(t_pswp **form)
{
	t_oplst	*tmp;
	char	*str;
	char	*line;

	line = NULL;
	str = "sa\nsb\nss\npa\npb\nra\nrb\nrr\nrra\nrrb\nrrr";
	if (!((*form)->lst = (t_oplst *)malloc(sizeof(t_oplst))))
		return (-1);
	(*form)->lst->op = -1;
	(*form)->lst->next = NULL;
	tmp = (*form)->lst;
	while (get_next_line(0, &line) > 0)
	{
		if (!(tmp->next = (t_oplst *)malloc(sizeof(t_oplst))))
			return (-1);
		tmp = tmp->next;
		tmp->next = NULL;
		if ((tmp->op = ft_istrstr(str, line)) == -1)
			return (clear_line(line));
		clear_line(line);
	}
	return (1);
}

int			init_vis_col(t_pswp *form, char **av)
{
	int		j;
	int		count;
	int		v;
	char	*vis;

	j = 1;
	count = 2;
	vis = "-v\n-c";
	while (count--)
	{
		if ((v = ft_istrstr(vis, av[j])) != -1)
		{
			if (v == 0)
				form->v = 1;
			else
				form->c = 1;
			j++;
		}
	}
	return (j);
}

void		print_rez(t_pswp *form)
{
	if (sort_check(form->a, 0) && !form->b)
	{
		if (form->c)
			put_color(form->amnt, 0, 1);
		write(1, "OK\x1b[0m\n", 7);
	}
	else
	{
		if (form->c)
			put_color(form->amnt, 0, 2);
		write(1, "KO\x1b[0m\n", 7);
	}
}

int			main(int ac, char **av)
{
	int		ret;
	t_pswp	*form;
	int		l;

	if (ac < 2)
		return (0);
	form = NULL;
	if (initialize_form(&form) == -1)
		return (display_err(&form));
	l = init_vis_col(form, av);
	ret = validate_input(&form, av, l, l - 1);
	if (form->amnt > 80)
		form->v = 0;
	if (ret == 0 || ret == -1 || (ret == 1 && !form->a->next))
		return (ret >= 0) ? 0 : display_err(&form);
	index_stack(form->a, form->amnt);
	if (!(ret = validate_operations(&form)))
		return (display_err(&form));
	do_operations(&form);
	print_rez(form);
	clean_form(&form);
	return (0);
}
