/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cchaudeu <cchaudeu@student.42berlin.d      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/08/12 21:15:07 by cchaudeu          #+#    #+#             */
/*   Updated: 2025/08/18 21:45:52 by cchaudeu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

/*int	main(void)
{
	char	*line;
	int		fd;

	fd = open("/home/cchaudeu/42_core/1_personal_github_repo/get_next_line/test"
			, 0_RDONLY);
	while (1)
	{
		line = get_next_line(fd);
		if (line == NULL)
			break;
		printf("%s", line);
		free(line);
	}
	return (0);
}*/

char	*get_next_line(int fd)
{
	static t_list	*stash = NULL;
	t_list			*current;
	char			*line;
	t_values		*tracker;

	if (fd < 0 || BUFFER_SIZE <= 0 || read(fd, &line, 0) < 0)
		return (NULL);
	current = stash;
	line = NULL;
	tracker = (t_values *)malloc(sizeof(t_values));
	tracker->red = 1;
	tracker->nl_pos = -1;
	tracker->fail = 0;
	while (has_nl(current, tracker) < 0 && !tracker->fail && tracker->red > 0)
		tracker->fail += read_into_stash(fd, &current, tracker);
	if (!tracker->fail)
		current->str = extract(&line, stash, current, tracker);
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

char	*extract(char **line, t_list *stash, t_list *current, t_values *tracker)
{
	int		len;
	char	*surplus;
	int		i;
	int		j;

	surplus = extract_surplus(current, tracker);
	len = strln(stash->str) + strln(current->str) + ((lstsi(stash) - 2)
			* BUFFER_SIZE);
	*line = (char *)malloc(sizeof(char) * (len + 1));
	if (!*line)
		tracker->fail++;
	i = 0;
	while (stash->next && *line)
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

char	*extract_surplus(t_list *current, t_values *tracker)
{
	char	*surplus;
	int		i;
	int		j;

	if (tracker->nl_pos < 0)
		return (NULL);
	surplus = (char *)malloc(sizeof(char) * (strln(current->str)
				- tracker->nl_pos));
	if (!surplus)
	{
		tracker->fail++;
		return (NULL);
	}
	i = 0;
	j = tracker->nl_pos + 1;
	while (current->str[j])
		surplus[i++] = current->str[j++];
	surplus[i] = '\0';
	current->str[tracker->nl_pos + 1] = '\0';
	return (surplus);
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
