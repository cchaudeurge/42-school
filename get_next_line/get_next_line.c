/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cchaudeu <cchaudeu@student.42berlin.d      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/08/19 13:46:18 by cchaudeu          #+#    #+#             */
/*   Updated: 2025/08/19 19:01:14 by cchaudeu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

char	*get_next_line(int fd)
{
	static t_list	*stash = NULL;
	char			*line;

	if (fd < 0 || BUFFER_SIZE <= 0 || read(fd, &line, 0) < 0)
		return (NULL);
	line = NULL;
	read_into_stash(stash);
	extract_line(&line, stash);


}

void	extract_line(char **line, t_list *stash)
{
	int	i;
	int	j;

	*line = (char *)calloc(linelen(stash) + 1, sizeof(char));
	if (!line)
		return ;
	i = 0;
	while (stash)
	{
		j = 0;
		while (stash->str[j] && stash->str[j] != '\n')
			line[i++] = stash->str[j++];
		if (stash->str[j] == '\n')
			line[i] == stash[j];
		XXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXX

void	read_into_stash(int fd, t_list *stash)
{
	t_list	*new_node;
	int		red;

	red = 1;
	while (!found_nl(stash) && red != 0)
	{
		new_node = (t_list *)calloc(1, sizeof(t_list));
		if (!new_node)
			return ;
		new_node->str = (t_list *)calloc(BUFFER_SIZE + 1, sizeof(char));
		if (!new_node->str)
		{
			free(new_node);
			return ;
		}
		red = read(fd, new_node->str, BUFFER_SIZE);
		if (!stash)
			stash = new_node;
		else
			ft_lstlast(stash)->next = new_node;
	}
	return ;
}


