
#include "so_long.h"

/*static const char	*g_map_errmsg[conditions_count] = {
	[extension] = "Map must be a .ber file.",
	[characters] = "Your map must only contain the following characters: 0, 1, C, E, P.",
	[map_exit] = "Your map must contain exactly one exit.",
	[start] = "Your map must contain exactly one starting position.",
	[collectibles] = "Your map must contain at least one collectible.",
	[shape] = "Your map must be rectangular.",
	[wall_enclosed] = "Your map must be wall enclosed.",
	[valid_path] = "Your map must have a valid path."
};*/

void	check_map(t_game *game)
{
	check_characters(game, "01CEP");
	check_exit(game);
	check_start(game);
	if (!game->map.collectibles)
		clean_exit(game, EXIT_FAILURE, map_err, "Your map must contain at least one collectible.");
	check_shape(game);
	check_wall_enclosed(game);
	check_path(game);
}

void	check_shape(t_game *game)
{
    int		i;
	int		length;

    i = 0;
    while (i < game->map.height)
    {
        length = (int)ft_strlen(game->map.array[i]);
		if (length != game->map.width)
			clean_exit(game, EXIT_FAILURE, map_err, "Your map must be rectangular.");
        i++;
    }
}

/*int has_only1(char **map, char element)
{
	int	element_count;

	if (!map)
		return (0);,
	element_count = 0;
	while (map)
	{
		if (strchr(map, element))
			element_count++;
		if (element_count > 1)
			return (0);
		map++;
	}
	return (element_count);
}*/

void	check_exit(t_game *game)
{
	size_t	exit_count;

	exit_count = count_element(game->map.array, EXIT);
	if (exit_count != 1)
		clean_exit(game, EXIT_FAILURE, map_err, "Your map must contain exactly one exit.");
}

void	check_start(t_game *game)
{
	size_t	start_count;

	start_count = count_element(game->map.array, START);
	if (start_count != 1)
		clean_exit(game, EXIT_FAILURE, map_err, "Your map must contain exactly one starting position.");
}


size_t	count_element(char **map, char element)
{
	size_t	element_count;
	int	i;

	element_count = 0;
	i = 0;
	while (map[i])
	{
		element_count += ft_charcount(map[i], element);
		i++;
	}
	return (element_count);
}

void	check_characters(t_game *game, char *valid_chars)
{
	int	i;
	int	j;

	i = 0;
	while (game->map.array[i])
	{
		j = 0;
		while (game->map.array[i][j])
		{
			if (!ft_strchr(valid_chars, game->map.array[i][j]))
				clean_exit(game, EXIT_FAILURE, map_err,
				"Your map must only contain the following characters: 0, 1, C, E, P.");
			j++;
		}
		i++;
	}
}

void	check_wall_enclosed(t_game *game)
{
	int	i;

	i = 0;
	while (i < game->map.width)
	{
		if (game->map.array[0][i] != WALL || game->map.array[game->map.height - 1][i]
			!= WALL)
			clean_exit(game, EXIT_FAILURE, map_err,
			"Your map must be wall enclosed.");
		i++;
	}
	i = 1;
	while (i < game->map.height - 2)
	{
		if (game->map.array[i][0] != WALL || game->map.array[i][game->map.width
			- 1] != WALL)
			clean_exit(game, EXIT_FAILURE, map_err,
			"Your map must be wall enclosed.");
		i++;
	}
}

/*int	is_wall_enclosed(char **map)
{
	size_t	i;
	size_t	j;
	size_t	length;

	i = 0;
	while (map[i])
	{
		if (i == 0 | !map[i + 1])
		{
			j = 0;
			while(map[i][j])
			{
				if (map[i][j] != WALL)
					return (0);
				j++;
			}
		}
		else
		{
			length = ft_strlen(map[i]);
			if (map[i][0] != WALL | map[i][length - 1] != WALL)
				return (0);
		}
		i++;
	}
	return (1);
}*/

void	check_path(t_game *game)
{
	char	**fill_map;

	fill_map = copy_map_array(game);
	flood_fill(fill_map, game->map.start.y, game->map.start.x, game);
	if (count_element(fill_map, EXIT) || count_element(fill_map, COLLECTIBLE))
	{
		free_array(fill_map);
		clean_exit(game, EXIT_FAILURE, map_err, "Your map must have a valid path.");
	}
	free_array(fill_map);
}

void	flood_fill(char **array, int y, int x, t_game *game)
{
	if (y < 0 || y >= game->map.height || x < 0 || x >=
		game->map.width || array[y][x] == WALL || array[y][x] == VISITED)
		return ;
	array[y][x] = VISITED;
	flood_fill(array, y - 1, x, game);
	flood_fill(array, y, x + 1, game);
	flood_fill(array, y + 1, x, game);
	flood_fill(array, y, x - 1, game);
}
		

char	**copy_map_array(t_game *game)
{
	char	**copy;
	int		i;

	copy = (char **)ft_calloc(game->map.height + 1, sizeof(char *));
	if (!copy)
		clean_exit(game, EXIT_FAILURE, sys_err, "malloc");
	i = 0;
	while (i < game->map.height)
	{
		copy[i] = ft_strdup((game->map.array)[i]);
		if (!copy[i])
		{
			free_array(copy);
			clean_exit(game, EXIT_FAILURE, sys_err, "malloc");
		}
		i++;
	}
	return (copy);
}



/*int	is_wall_enclosed(char **map)
{
	size_t	x;
	size_t	y;
	size_t	height;
	size_t	length;

	if(!map)
		return (0);
	x = 0;
	height = array_len(map);
	while (map[x])
	{
		if (x == 0 | x == height - 1)
		{
			y = 0;
			while(map[x][y])
			{
				if (map[x][y] != WALL)
					return (0);
				y++;
			}
		}
		else
		{
			length = ft_strlen(map[x]);
			if (map[x][0] != WALL | map[x][length - 1] != WALL)
				return (0);
		}
		i++;
	}
	return (1);
}*/

/*int	is_wall_enclosed(char **map)
{
	size_t	i;
	size_t	height;
	size_t	length;
	size_t	max_length;

	if(!map)
		return (0);
	i = 0;
	height = array_len(map);
	max_length = 0;
	while (i < height | i < ft_strlen(map[0]) | i <
	{
		//Top
		length = ft_strlen(map[0]);
		if (i < length && map[0][i] != WALL)
			return (0);
		//Left
		if (i < height && map[i][0] != WALL)
			return (0);
		//Bottom
		length =  ft_strlen(map[height - 1]);  
		if (i < length && map[height - 1][i] != WALL)
			return (0);
		//Right
		length = ft_strlen(map[i]);
		if (i < height && map[i][length - 1] != WALL)
			return (0);
		i++;
	}
	i = 0;
	j = array_len(map) - 1;
	while (map && map[1][i])
	{
		if (map[0][i] != WALL)
			return (0);
		i++;
	}
	*/




