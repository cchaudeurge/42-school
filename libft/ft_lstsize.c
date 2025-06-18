#include "libft.h"

int	ft_lstsize(t_list *lst)
{
	if (!lst)
		return (0);
	if (lst->next == NULL)
		return (1);
	else
	{
		return(1 + ft_lstsize(lst_>next));
	}
}
