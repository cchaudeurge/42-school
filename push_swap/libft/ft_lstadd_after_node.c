#include "libft.h"

void	ft_lstadd_after_node(t_list **node, t_list *new)
{
	if (!node || !new)
		return ;
	if (!*node)
		*node = new;
	else
	{
		new->next = (*node)->next;
		(*node)->next = new;
	}
}
	
