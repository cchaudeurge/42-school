/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main_bonus.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cchaudeu <cchaudeu@student.42berlin.d      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/08/19 00:23:09 by cchaudeu          #+#    #+#             */
/*   Updated: 2025/09/14 12:12:15 by cchaudeu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"
#include <fcntl.h> 

char	*get_next_line(int fd);

int	main(void)
{
	char	*line1;
	char	*line2;
	char	*line3;
	int		fd1;
	int		fd2;
	int		fd3;

	fd1 = open("Test.txt", O_RDONLY);
	fd2 = open("test1", O_RDONLY);
	fd3 = open("test2", O_RDONLY);
	while (1)
	{
		line1 = get_next_line(fd1);
		printf("%s", line1);
		line2 = get_next_line(fd2);
		printf("%s", line2);
		line3 = get_next_line(fd3);
		printf("%s", line3);
		if (!line1 && !line2 && !line3)
		{
			free(line1);
			free(line2);
			free(line3);
			break;
		}
		free(line1);
		free(line2);
		free(line3);
		printf("\n");
	}
	close(fd1);
	close(fd2);
	close(fd3);
	return (0);
}
