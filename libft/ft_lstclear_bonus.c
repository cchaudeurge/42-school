/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstclear_bonus.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cchaudeu <cchaudeu@student.42berlin.d      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/18 17:54:54 by cchaudeu          #+#    #+#             */
/*   Updated: 2025/06/23 15:28:41 by cchaudeu         ###   ########.fr       */
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
