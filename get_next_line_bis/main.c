/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cchaudeu <cchaudeu@student.42berlin.d      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/08/19 00:23:09 by cchaudeu          #+#    #+#             */
/*   Updated: 2025/08/29 20:55:23 by cchaudeu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

char	*get_next_line(int fd);

int	main(void)
{
	char	*line;
	int		fd;

	fd = open("/home/cchaudeu/42_core/1_personal_github_repo/get_next_line/test", O_RDONLY);
	while (1)
	{
		line = get_next_line(fd);
		if (line == NULL)
		{		
			printf("(null)");
			break;
		}
		printf("%s", line);
		free(line);
	}
	return (0);
}
