#include "libft.h"

t_lst	*ft_lstlast(t_list *lst)
{
	if (!lst)
		return (NULL);
	if (lst->next == NULL)
		return (lst);
	else
		return (ft_lstlast(lst->next));
}
