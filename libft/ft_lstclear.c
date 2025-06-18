#include "libft.h"

void	ft_lstclear(t_list **lst, void (*del)(void *))
{
	t_list	*new_first;

	if (!lst || !*lst || !del)
		return ;
	new_first = *lst;
	while (*new_first->next)
	{
		new_first = *new_first->next;
		ft_delone(*lst, del);
		*lst = new_first;
	}	
	(*del)(*lst);
	*lst = NULL;
}
