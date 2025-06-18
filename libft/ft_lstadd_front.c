#include "libft.h"

void	ft_lsadd_front(t_list **lst, t_list *new)
{
	if (!lst || !new)
		return ;
	if (!*lst)
		return ;
	new->next = *lst;
	*lst = new;
}
