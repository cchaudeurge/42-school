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

void	*parse_init_check_map(t_game *game, char *map_path)
{
	int	fd;
	char 	**map_array;

	check_extension(map_path);
	fd = open(map_path);
	if (fd < 0)
		clean_exit(game, EXIT_FAILURE, sys_err, "open");
	map_array = create_map_array(fd, game);
	close(fd);
	game->map.array = map_array;
	game->map.width = ft_strlen(*map_array);
	game->map.height = array_len(map_array);
	game->map.collectibles = count_element(map_array, COLLECTIBLE);
	locate_start(game);
	check_map(game);
}

void	check_extension(char *map_path)
{
	size_t	length;

	length = ft_strlen(map_path);
	if (length > 4 && ft_strncmp(map_path + length - 4, ".ber", 4) == 0)
		return ;
	else
		error_exit(map_err, g_map_errmsg[extension]);
}

t_list	*create_map_list(int fd, t_game game)
{
	t_list	*line_lst;
	char	*line;
	t_list	*new_node;

    line_lst = NULL;
	line = gnl_without_nl(fd);
	while (line)
	{
		new_node = ft_lstnew(line);
		if (!new_node)
		{
			free(line);
			ft_lstclear(&line_lst);
			close(fd);
			clean_exit(game, EXIT_FAILURE, sys_err, "malloc");
		}
		ft_lstadd_back(&line_lst, new_node);
		line = gnl_without_nl(fd);
	}
	return (line_lst);
}

char	**create_map_array(int fd, t_game *game)
{
    char    **map;
    t_list	*line_lst;
	t_list	*current;
	int		i;

	line_lst = create_map_lst(fd);
    map = (char **)ft_calloc(sizeof(char *) * (ft_lstsize(line_lst) + 1));
    if (!map)
	{
		ft_lstclear(&line_lst);
		close(fd);
		clean_exit(game, EXIT_FAILURE, sys_err, "malloc");
	}
    i = 0;
    while (line_lst)
	{
		current = line_lst;
		map[i] = line_lst->content;
		line_lst = line_lst->next;
		free(current);
	}
	return (map);
}

size_t	array_len(char **map)
{
	size_t	element_count;
	int		i;

	element_count = 0;
	i = 0;
	while (map[i++])
		element_count++;
	return (element_count);
}

void	locate_start(t_game *game)
{
	int	i;
	int	j;

	i = 0;
	while (game->map.array[i])
	{
		if (!ft_strchr(game->map.array[i], START))
			i++;
		else
		{
			game->map.start.y = i;
			game->map.start.x = (int)ft_strchr(game->map.array[i], START);
			return ;
		}
	}
}
