#include "push_swap.h"

void		full_ab(t_pswp *form, t_stack **va, t_stack **vb)
{
	int		t;

	if (form->c)
		ft_printf("\x1b[1;40m");
	ft_printf("%*s", form->amnt - (*va)->index, " ");
	if (form->c)
		put_color(form->amnt, (*va)->index, 0);
	t = (*va)->index + 1;
	while (t--)
		ft_printf("-");
	ft_printf("    ");
	if (form->c)
		put_color(form->amnt, (*vb)->index, 0);
	t = (*vb)->index + 1;
	while (t--)
		ft_printf("-");
	ft_printf("%*s\x1b[0m\n", form->amnt - (*vb)->index, " ");
	*va = (*va)->next;
	*vb = (*vb)->next;
}

void		emptyb_fulla(t_pswp *form, t_stack **va)
{
	int		t;

	if (form->c)
		ft_printf("\x1b[1;40m");
	ft_printf("%*s", form->amnt - (*va)->index, " ");
	t = (*va)->index + 1;
	if (form->c)
		put_color(form->amnt, (*va)->index, 0);
	while (t--)
		ft_printf("-");
	ft_printf("    %*s\x1b[0m\n", form->amnt + 1, " ");
	*va = (*va)->next;
}

void		emptya_fullb(t_pswp *form, t_stack **vb)
{
	int		t;

	if (form->c)
		ft_printf("\x1b[1;40m");
	ft_printf("%*s    ", form->amnt + 1, " ");
	t = (*vb)->index + 1;
	if (form->c)
		put_color(form->amnt, (*vb)->index, 0);
	while (t--)
		ft_printf("-");
	ft_printf("%*s\x1b[0m\n", form->amnt - (*vb)->index, " ");
	*vb = (*vb)->next;
}

void		emptyab(t_pswp *form, int *emptya, int *emptyb)
{
	if (form->c)
		ft_printf("\x1b[1;40m");
	ft_printf("%*s    %*s\x1b[0m\n", form->amnt + 1, " ", form->amnt + 1, " ");
	*emptya = *emptya - 1;
	*emptyb = *emptyb - 1;
}

void		visualise(t_pswp *form, int op, int emptya, int emptyb)
{
	t_stack	*va;
	t_stack *vb;

	va = form->a;
	vb = form->b;
	if (form->amnt > 10)
		(form->amnt > 50) ? usleep(80000) : usleep(120000);
	else
		usleep(250000);
	ft_printf("\x1b[2J");
	while (va || vb)
	{
		while (emptya && emptyb)
			emptyab(form, &emptya, &emptyb);
		while (emptya-- > 0)
			emptya_fullb(form, &vb);
		while (emptyb-- > 0)
			emptyb_fulla(form, &va);
		while (va || vb)
			full_ab(form, &va, &vb);
	}
	if (op)
		put_greeting(form->c);
}
