/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parsing.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cchaudeu <cchaudeu@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/20 23:50:58 by cchaudeu          #+#    #+#             */
/*   Updated: 2025/10/28 10:44:34 by cchaudeu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void	parse_map(char *map_path)
{
	/*check that the map file is a .ber*/
	/*Open the map > fd*/
	/*Fill map array*/
	/*Check map conditions*/
}

char	**create_map_array(int fd)
{
    char    **map;
    int     line_count;
    int     i;

    line_count = count_map_lines(fd);
    map = (char **)ft_calloc(sizeof(char *) * (line_count + 1));
    if (!map)
        //XXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXX
    i = 0;
    while (line_count--)
    {
        map[i] = get_next_line(fd);
    }
    return (map);
}

int count_map_lines(int fd)
{
    char    *line;
    int     line_count;

    line_count = 0;
    line = get_next_line(fd);
    while (line)
    {
        line_count++;
        free(line);
        line = get_next_line(fd);
    }
    return (line_count);
}
void    remove_nl(char **map)
{
    int i;
}

int isrectangle(char **map)
{
    int i;

    if (!map)
        return (0);
    i = 0;
    while (map[i] && map[i+1])
    {
        if (ft_strlen(map[i] != ft_strlen(map[i+1])))
            return (0);
        i++;
    }
    return  (1);
}
