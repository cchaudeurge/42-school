/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstadd_after_node.c                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cchaudeu <cchaudeu@student.42berlin.d      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/03/18 20:31:00 by cchaudeu          #+#    #+#             */
/*   Updated: 2026/03/18 20:32:26 by cchaudeu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

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
