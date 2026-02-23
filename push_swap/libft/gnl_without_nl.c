/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   gnl_without_nl.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cchaudeu <cchaudeu@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/08/19 13:46:18 by cchaudeu          #+#    #+#             */
/*   Updated: 2025/12/11 00:19:51 by cchaudeu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static size_t	linelen(t_list *buff)
{
	size_t	length;
	int		j;

	length = 0;
	while (buff)
	{
		j = 0;
		while (((char *)buff->content)[j] && ((char *)buff->content)[j] != '\n')
		{
			length++;
			j++;
		}
		if (((char *)buff->content)[j] == '\n')
			return (length);
		buff = buff->next;
	}
	return (length);
}

static int	read_into_buff(int fd, t_list **buff)
{
	char	*buffer;
	int		red;
	t_list	*new_node;

	while (1)
	{
		if (*buff && ft_strchr((char *)(ft_lstlast(*buff)->content), '\n'))
			return (0);
		buffer = (char *)ft_calloc(42 + 1, sizeof(char));
		if (!buffer)
			return (-1);
		red = read(fd, buffer, 42);
		if (red <= 0)
			return (free(buffer), red);
		new_node = ft_lstnew(buffer);
		if (!new_node)
			return (free(buffer), -1);
		ft_lstadd_back(buff, new_node);
	}
}

static int	extract_line_and_surplus(t_list *buff, char **line, char *surplus)
{
	int	i;
	int	j;

	*line = (char *)ft_calloc(linelen(buff) + 1, sizeof(char));
	if (!*line)
		return (-1);
	i = 0;
	while (buff)
	{
		j = 0;
		while (((char *)buff->content)[j] && ((char *)buff->content)[j] != '\n')
			(*line)[i++] = ((char *)buff->content)[j++];
		if (((char *)buff->content)[j] == '\n')
		{
			j++;
			break ;
		}
		buff = buff->next;
	}
	i = 0;
	while (buff && ((char *)buff->content)[j])
		surplus[i++] = ((char *)buff->content)[j++];
	return (0);
}

static int	extract_and_clean_buff(t_list **buff, char **line, int *fail)
{
	t_list	*next_line;

	if (!buff || !*buff)
		return (0);
	next_line = (t_list *)ft_calloc(1, sizeof(t_list));
	if (!next_line)
		return (-1);
	next_line->content = (char *)ft_calloc(42 + 1, sizeof(char));
	if (!next_line->content)
		return (free(next_line), -1);
	*fail += extract_line_and_surplus(*buff, line, (char *)next_line->content);
	ft_lstclear(buff, free);
	*buff = next_line;
	return (0);
}

char	*gnl_without_nl(int fd)
{
	static t_list	*buff[100];
	char			*line;
	int				fail;

	if (fd < 0 || fd >= 100 || 42 <= 0)
		return (ft_lstclear(&buff[fd], free), NULL);
	line = NULL;
	fail = read_into_buff(fd, &buff[fd]);
	fail += extract_and_clean_buff(&buff[fd], &line, &fail);
	if (fail || line[0] == '\0')
	{
		if (buff[fd])
			ft_lstclear(&buff[fd], free);
		if (line)
			free(line);
		return (NULL);
	}
	return (line);
}
