/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: screight <screight@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/08/04 10:56:52 by screight          #+#    #+#             */
/*   Updated: 2019/08/28 19:17:04 by screight         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int			main(int ac, char **av)
{
	int		ret;
	t_pswp	*form;

	if (ac < 2)
		return (0);
	form = NULL;
	if (initialize_form(&form) == -1)
		return (display_err(&form));
	ret = validate_input(&form, av, 1, 0);
	if (ret == 0 || ret == -1 || (ret > 0 && !form->a->next))
		return (ret >= 0) ? 0 : display_err(&form);
	index_stack(form->a, form->amnt);
	algorithm(&form);
	clean_form(&form);
	return (ret);
}
