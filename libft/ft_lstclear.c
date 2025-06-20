/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstclear.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cchaudeu <cchaudeu@student.42berlin.d      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/18 17:54:54 by cchaudeu          #+#    #+#             */
/*   Updated: 2025/06/20 20:43:37 by cchaudeu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_lstclear(t_list **lst, void (*del)(void *))
{
	t_list	*new_first;

	if (!lst || !*lst || !del)
		return ;
	new_first = *lst;
	while (new_first->next)
	{
		new_first = new_first->next;
		ft_lstdelone(*lst, del);
		*lst = new_first;
	}
	ft_lstdelone(*lst, del);
	*lst = NULL;
}
