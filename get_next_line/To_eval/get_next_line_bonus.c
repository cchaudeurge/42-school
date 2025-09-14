/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_bonus.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cchaudeu <cchaudeu@student.42berlin.d      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/08/19 13:46:18 by cchaudeu          #+#    #+#             */
/*   Updated: 2025/08/30 01:24:39 by cchaudeu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

char	*get_next_line(int fd)
{
	static t_list	*stash[1024];
	char			*line;
	int				fail;

	if (fd < 0 || BUFFER_SIZE <= 0)
		return (NULL);
	line = NULL;
	fail = read_into_stash(fd, &stash[fd]);
	fail += extract_line(&line, stash[fd]);
	fail += clean_stash(&stash[fd]);
	if (fail || line[0] == '\0')
	{
		if (stash[fd])
			free_lst(&stash[fd]);
		if (line)
			free(line);
		return (NULL);
	}
	return (line);
}

int	clean_stash(t_list **stash)
{
	t_list	*next_line;

	next_line = (t_list *)calloc(1, sizeof(t_list));
	if (!next_line)
		return (1);
	next_line->str = (char *)calloc(BUFFER_SIZE + 1, sizeof(char));
	if (!next_line->str)
	{
		free(next_line);
		return (1);
	}
	extract_surplus(*stash, next_line->str);
	free_lst(stash);
	*stash = next_line;
	return (0);
}

void	extract_surplus(t_list *stash, char *next_line_str)
{
	int	i;
	int	j;

	i = 0;
	j = 0;
	while (ft_lstlast(stash)->str[i] && ft_lstlast(stash)->str[i] != '\n')
		i++;
	if (ft_lstlast(stash)->str[i] == '\n')
		i++;
	while (ft_lstlast(stash)->str[i])
		next_line_str[j++] = ft_lstlast(stash)->str[i++];
}

int	extract_line(char **line, t_list *stash)
{
	int	i;
	int	j;

	*line = (char *)calloc(linelen(stash) + 1, sizeof(char));
	if (!*line)
		return (1);
	i = 0;
	while (stash)
	{
		j = 0;
		while (stash->str[j] && stash->str[j] != '\n')
			(*line)[i++] = stash->str[j++];
		if (stash->str[j] == '\n')
			(*line)[i] = stash->str[j];
		stash = stash->next;
	}
	return (0);
}

int	read_into_stash(int fd, t_list **stash)
{
	t_list	*new_node;
	int		red;

	red = 1;
	while (!found_nl(*stash) && red > 0)
	{
		new_node = (t_list *)calloc(1, sizeof(t_list));
		if (!new_node)
			return (1);
		new_node->str = (char *)calloc(BUFFER_SIZE + 1, sizeof(char));
		if (!new_node->str)
		{
			free(new_node);
			return (1);
		}
		red = read(fd, new_node->str, BUFFER_SIZE);
		if (!*stash)
			*stash = new_node;
		else
			ft_lstlast(*stash)->next = new_node;
	}
	return (0);
}
