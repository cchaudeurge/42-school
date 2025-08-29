/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cchaudeu <cchaudeu@student.42berlin.d      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/08/12 21:15:07 by cchaudeu          #+#    #+#             */
/*   Updated: 2025/08/16 02:25:39 by cchaudeu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"
#include <fcntl.h>

int	main(void)
{
	char	*line;
	int		fd;

	fd = open("/home/cchaudeu/42_core/1_personal_github_repo/get_next_line/test"
			, 0_RDONLY);
	while (1)
	{
		line = get_next_line(fd);
		if (line = NULL)
			break;
		printf("%s", line);
		free(line);
	}
	return (0);
}

char	*get_next_line(int fd)
{
	static char	*stash = NULL;
	t_list		*line;
	int			nl_pos;
	int			fail;
	
	if (fd < 0 || BUFFER_SIZE <= 0 || read(fd, &nl_pos, 0) < 0)
		return (NULL);
	line = NULL;
	fail = 0;
	while (has_nl(stash, &nl_pos) >= 0)
		fail += add_until_nl
}

int	add_until_nl_and_stash(t_list *line, char *str, int nl_pos, char *stash)
{
	char	*2add2line;

	2add2line = (char *)malloc(sizeof(char) * (nl_pos + 2));
	if (!2add2line)
		return (1);
	if (!stash)

int	has_nl(char *str, int *nl_pos)
{
	int	i;

	*nl_pos = -1;
	if (!str)
		return (*nl_pos);
	i = 0;
	while (str[i])
	{
		if (str[i] == '\n')
		{
			*nl_pos = i;
			return (*nl_pos);
		}
		i++;
	}
	return (*nl_pos);
}

void	read_and_add2line(char *stash, int *nl_pos, int *red, t_list *line)
{
	char	*buffer;
	
	buffer = (char *)malloc(sizeof(char) * (BUFFER_SIZE + 1));
	if (!buffer)
		return ;
	while (*red > 0)
}
