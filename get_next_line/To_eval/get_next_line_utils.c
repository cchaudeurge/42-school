/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_utils.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cchaudeu <cchaudeu@student.42berlin.d      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/08/19 13:52:07 by cchaudeu          #+#    #+#             */
/*   Updated: 2025/09/14 15:03:48 by cchaudeu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

void	*ft_calloc(size_t nbr, size_t size)
{
	void			*ptr;
	unsigned char	*pointer;
	size_t			i;

	if (nbr == 0 || size == 0)
		return (malloc(0));
	if (nbr > SIZE_MAX / size)
		return (NULL);
	ptr = malloc(nbr * size);
	if (ptr == NULL)
		return (NULL);
	pointer = (unsigned char *)ptr;
	i = nbr * size;
	while (i--)
		pointer[i] = 0;
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
	int	j;

	length = 0;
	while (stash)
	{
		j = 0;
		while (stash->str[j] && stash->str[j] != '\n')
		{
			length++;
			j++;
		}
		if (stash->str[j] == '\n')
		{
			length++;
			return (length);
		}
		stash = stash->next;
	}
	return (length);
}

void	free_lst(t_list **stash)
{
	t_list	*next;

	while (*stash)
	{
		free((*stash)->str);
		next = (*stash)->next;
		free(*stash);
		*stash = next;
	}
	*stash = NULL;
}
