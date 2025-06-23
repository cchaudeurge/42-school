/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstsize_bonus.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cchaudeu <cchaudeu@student.42berlin.d      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/18 17:56:17 by cchaudeu          #+#    #+#             */
/*   Updated: 2025/06/23 15:27:43 by cchaudeu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	ft_lstsize(t_list *lst)
{
	int		size;
	t_list	*current_node;

	if (!lst)
		return (0);
	size = 1;
	current_node = lst;
	while (current_node->next)
	{
		size++;
		current_node = current_node->next;
	}
	return (size);
}

/*int	ft_lstsize(t_list *lst)
{
	if (!lst)
		return (0);
	if (lst->next == NULL)
		return (1);
	else
	{
		return (1 + ft_lstsize(lst->next));
	}
}*/
