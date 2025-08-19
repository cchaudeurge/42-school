/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_utils.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cchaudeu <cchaudeu@student.42berlin.d      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/08/19 13:52:07 by cchaudeu          #+#    #+#             */
/*   Updated: 2025/08/19 18:51:39 by cchaudeu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

void	*ft_calloc(size_t nbr, size_t size)
{
	void	*ptr;
	size_t	i;
	
	if (nbr == 0 || size == 0)
		return (malloc(0));
	if (nbr > INT_MAX / size)
		return (NULL);
	ptr = malloc(nbr * size);
	if (ptr == NULL)
		return (NULL);
	i = nbr * size;
	while (i--)
		ptr[i - 1] = 0;
	return (ptr);
}

t_list	*ft_lstlast(t_list *lst)
{
	t_list	*current;

	current = lst;
	while (current && current->next)
		current = current->next;
	return (current);
}

int	found_nl(t_list *stash)
{
	int		i;
	t_list	*last_node;

	if (!stash)
		return (0);
	i = 0;
	last_node = ft_lstlast(stash);
	while (last_node->str[i])
	{
		if (last_node->str[i] == '\n')
			return (1);
		i++;
	}
	return (0);
}

size_t	linelen(t_list *stash)
{
	int	length;
	int j;
	
	length = 0;
	while (stash)
	{
		j = 0;
		while (stash->str[j] && stash->str[j] != '\n')
		{
			length++;
			j++;
		}
		if (stash->str[j] == 'n')
		{
			length++;
			return (length);
		}
		stash = stash->next;
	}
	return (length);
}
