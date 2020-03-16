#ifndef PUSH_SWAP_H
# define PUSH_SWAP_H

# define SA 0
# define SB 3
# define SS 6
# define PA 9
# define PB 12
# define RA 15
# define RB 18
# define RR 21
# define RRA 24
# define RRB 28
# define RRR 32

# include <unistd.h>
# include <limits.h>
# include <stdlib.h>
# include "libft.h"
# include "libftprintf.h"

typedef struct		s_opns
{
	int				arr;
	int				brr;
	int				ar;
	int				br;
	int				adir;
	int				bdir;
	int				rot;
	int				maxdir;
	int				mindir;
}					t_opns;

typedef struct		s_oplst
{
	struct s_oplst	*next;
	int				op;
}					t_oplst;

typedef struct		s_stack
{
	struct s_stack	*next;
	long			value;
	int				index;
}					t_stack;

typedef struct		s_push_swap
{
	t_oplst			*lst;
	t_stack			*a;
	t_stack			*b;
	t_stack			*af;
	t_stack			*bf;
	int				b1;
	int				b2;
	int				amnt;
	int				v;
	int				c;
}					t_pswp;

int					initialize_form(t_pswp **form);
int					validate_input(t_pswp **form, char **av, int j, int sum);
int					display_err(t_pswp **form);
void				swap(t_stack *stack, int pr, int s);
void				push(t_stack **s1, t_stack **s2, int pr, int s);
void				rotate(t_stack **start, t_stack **end, int pr, int s);
void				rev_rotate(t_stack **start, t_stack **end, int pr, int s);
t_stack				*make_stack(char *s_value, int tr);
void				index_stack(t_stack *s, int amount);
void				algorithm(t_pswp **form);
int					minialg(t_pswp **form);
void				split_stack(t_pswp **form);
void				clean_stack(t_stack **top);
int					sort_check(t_stack *tmp, int order);
void				do_sort(t_pswp **form);
void				sort_stack(t_pswp **form);
int					find_first(t_stack *tmp, int st, int end);
int					find_last(t_stack *tmp, int st, int end);
int					find_place(t_pswp *form, int index);
void				clean_form(t_pswp **form);
void				get_to_top1(t_pswp **form, int r, int rr, char ch);
void				get_to_top2(t_pswp **form, t_opns *op, int s, int ss);
void				get_min_to_top(t_pswp **form, int ind, int i, int j);
int					count_stack(t_stack *stack);
void				do_operations(t_pswp **form);
void				visualise(t_pswp *form, int op, int emptya, int emptyb);
void				put_color(int amnt, int i, int text);
void				put_greeting(int color);

#endif
