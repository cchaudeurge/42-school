/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cchaudeu <cchaudeu@student.42berlin.d      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/08/12 21:15:07 by cchaudeu          #+#    #+#             */
/*   Updated: 2025/08/19 02:04:20 by cchaudeu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

char	*get_next_line(int fd)
{
	static t_list	*stash = NULL;
	t_list			*current;
	char			*line;
	t_values		*tracker;
	t_list			*buffer;

	buffer = NULL;
	if (fd < 0 || BUFFER_SIZE <= 0 || read(fd, &line, 0) < 0)
		return (NULL);
	if (initialize(stash, &current, &line, &tracker))
		return (NULL);
	while (has_nl(current, tracker) < 0 && !tracker->fail && tracker->red > 0)
		tracker->fail += read_into_stash(fd, &current, tracker);
	if (!tracker->fail)
	{
		buffer = extract(&line, stash, current, tracker);
		current = buffer;
	}
	if (tracker->fail)
		return (free_all(&stash, &current, &line, &tracker));
	free_lst(stash);
	stash = current;
	return (line);
}

char	*free_all(t_list	**stashptr, t_list **currentptr, char **line,
		t_values **trackerptr)
{
	if (*stashptr)
	{
		free_lst(*stashptr);
		*stashptr = NULL;
	}
	if (*currentptr)
		free_lst(*currentptr);
	if (*line)
		free(*line);
	if (*trackerptr)
		free(*trackerptr);
	return (NULL);
}

t_list	*extract(char **line, t_list *stash, t_list *current, t_values *tracker)
{
	int		len;
	t_list	*surplus;
	int		i;
	int		j;

	surplus = NULL;
	if (tracker->nl_pos >= 0)
	{
		surplus = extract_surplus(current->str, tracker);
		current->str[tracker->nl_pos + 1] = '\0';
	}
	len = linelen(stash);
	*line = (char *)malloc(sizeof(char) * (len + 1));
	if (!*line)
		tracker->fail++;
	i = 0;
	while (stash && *line)
	{
		j = 0;
		while (stash->str[j])
			*line[i++] = stash->str[j++];
		stash = stash->next;
	}
	if (*line)
		*line[i] = '\0';
	return (surplus);
}

t_list	*extract_surplus(char *str, t_values *tracker)
{
	t_list	*extra;
	char	*surplusptr;

	extra = (t_list *)malloc(sizeof(t_list));
	if (!extra)
	{
		tracker->fail++;
		return (NULL);
	}
	extra->str = (char *)malloc(sizeof(char) * (strln(str) - tracker->nl_pos));
	if (!extra->str)
	{
		tracker->fail++;
		return (extra);
	}
	extra->next = NULL;
	surplusptr = extra->str;
	str += tracker->nl_pos + 1;
	while (*str)
		*surplusptr++ = *str++;
	*surplusptr = '\0';
	return (extra);
}

int	read_into_stash(int fd, t_list **current, t_values *tracker)
{
	t_list	*new;

	new = (t_list *)malloc(sizeof(t_list));
	if (!new)
		return (1);
	new->next = NULL;
	if (*current)
		(*current)->next = new;
	*current = new;
	new->str = (char *)malloc(sizeof(char) * (BUFFER_SIZE + 1));
	if (!new->str)
		return (1);
	tracker->red = read(fd, new->str, BUFFER_SIZE);
	new->str[tracker->red] = '\0';
	return (0);
}
