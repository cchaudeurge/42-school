/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_utils.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cchaudeu <cchaudeu@student.42berlin.d      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/08/16 19:25:12 by cchaudeu          #+#    #+#             */
/*   Updated: 2025/08/19 01:10:36 by cchaudeu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

int	linelen(t_list *stash)
{
	int	length;
	int	i;

	length = 0;
	while (stash)
	{
		i = 0;
		while (stash->str[i])
		{
			length++;
			i++;
		}
		stash = stash->next;
	}
	return (length);
}

int	strln(char *str)
{
	int	i;

	i = 0;
	if (!str)
		return (i);
	while (str[i])
		i++;
	return (i);
}

int	lstsi(t_list *stash)
{
	int		size;
	t_list	*current_node;

	if (!stash)
		return (0);
	size = 1;
	current_node = stash;
	while (current_node->next)
	{
		size++;
		current_node = current_node->next;
	}
	return (size);
}

void	free_lst(t_list *stash)
{
	t_list	*next;

	while (stash)
	{
		free(stash->str);
		next = stash->next;
		free(stash);
		stash = next;
	}
}

int	has_nl(t_list *current, t_values *tracker)
{
	int	i;

	tracker->nl_pos = -1;
	if (!current)
		return (tracker->nl_pos);
	i = 0;
	while (current->str[i])
	{
		if (current->str[i] == '\n')
		{
			tracker->nl_pos = i;
			return (tracker->nl_pos);
		}
		i++;
	}
	return (tracker->nl_pos);
}

int	initialize(t_list *stash, t_list **current, char **line, t_values **tracker)
{
	*current = stash;
	*line = NULL;
	*tracker = (t_values *)malloc(sizeof(t_values));
	if (!tracker)
		return (1);
	(*tracker)->red = 1;
	(*tracker)->nl_pos = -1;
	(*tracker)->fail = 0;
	return (0);
}
