#include "libft.h"

void	ft_lstdel(t_list **alst, void (*del)(void *, size_t))
{
	t_list	*next_lst;

	if (!(*alst) || !(alst))
		return ;
	while (*alst)
	{
		next_lst = (*alst)->next;
		del((*alst)->content, (*alst)->content_size);
		free(*alst);
		*alst = next_lst;
	}
	*alst = NULL;
}
