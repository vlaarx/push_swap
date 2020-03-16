#include "push_swap.h"

int			count_steps(t_pswp *form, t_opns *op, int ar, int j)
{
	int		maxrr;
	int		maxr;
	int		maxdir;

	op->ar = ar;
	op->arr = count_stack(form->a) - op->ar;
	if ((op->br = find_first(form->b, j, j + 1)) != -1)
		op->brr = count_stack(form->b) - op->br;
	maxr = (op->ar > op->br) ? op->ar : op->br;
	maxrr = (op->arr > op->brr) ? op->arr : op->brr;
	op->rot = (maxr <= maxrr) ? 1 : 0;
	op->adir = (op->rot == 1) ? op->ar : op->arr;
	op->bdir = (op->rot == 1) ? op->br : op->brr;
	maxdir = (op->adir > op->bdir) ? op->adir : op->bdir;
	return (maxdir);
}

void		find_fastest(t_pswp *form, t_opns *op, t_opns *bast)
{
	int		tmp;
	t_stack	*b;

	b = form->b;
	while (b)
	{
		tmp = count_steps(form, bast, find_place(form, b->index), b->index);
		if (tmp < op->maxdir)
		{
			op->maxdir = tmp;
			op->rot = bast->rot;
			op->adir = bast->adir;
			op->bdir = bast->bdir;
			op->mindir = (op->adir <= op->bdir) ? op->adir : op->bdir;
		}
		if (bast->ar + bast->brr < tmp || bast->br + bast->arr < tmp)
		{
			op->ar = bast->ar;
			op->arr = bast->arr;
			op->br = bast->br;
			op->brr = bast->brr;
		}
		b = b->next;
	}
}

void		init_opns(t_opns *op, int max)
{
	op->maxdir = max;
	op->mindir = max;
	op->ar = max;
	op->arr = max;
	op->br = max;
	op->brr = max;
	op->rot = max;
	op->adir = max;
	op->bdir = max;
}

void		do_sort(t_pswp **form)
{
	t_opns	op;
	t_opns	bast;

	while ((*form)->b)
	{
		init_opns(&op, (*form)->amnt + 1);
		bast.ar = (*form)->amnt + 1;
		bast.br = (*form)->amnt + 1;
		bast.arr = (*form)->amnt + 1;
		bast.brr = (*form)->amnt + 1;
		bast.maxdir = (*form)->amnt + 1;
		find_fastest(*form, &op, &bast);
		if ((op.ar + op.brr < op.br + op.arr) && (op.ar + op.brr < op.maxdir))
			get_to_top1(form, op.ar, op.brr, 'a');
		else if (op.br + op.arr < op.maxdir)
			get_to_top1(form, op.br, op.arr, 'b');
		else
			get_to_top2(form, &op, op.maxdir - op.mindir, op.mindir);
		push(&(*form)->b, &(*form)->a, 1, 1);
		(*form)->bf = (*form)->b;
		while ((*form)->bf && (*form)->bf->next)
			(*form)->bf = (*form)->bf->next;
	}
}

void		algorithm(t_pswp **form)
{
	if (sort_check((*form)->a, 0))
		return ;
	if ((*form)->amnt < 10 && !minialg(form))
		return ;
	(*form)->b1 = (*form)->amnt / 3;
	(*form)->b2 = 2 * (*form)->b1;
	if ((*form)->amnt < 10)
		return ;
	split_stack(form);
	do_sort(form);
	get_min_to_top(form, -1, 0, 0);
}
