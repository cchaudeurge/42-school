
void	check_map(t_map *map)
{
	check_characters(map, "01CEP");
	check_exit(map);
	check_start(map);
	if (!map->collectibles)
	{
		free_map(map);
		error_exit(map_error, g_map_errmsg[collectibles]);
	}
	check_shape(map);
	check_wall_enclosed(map);
	check_path;
}

void	check_shape(t_map *map)
{
    size_t	i;
	size_t	length;

    i = 0;
    while (i < map->height)
    {
        length = ft_strlen(map->array[i]);
		if (length != map->width)
		{
			free_map(map);
			error_exit(map_error, g_map_errmsg[shape]);
		}
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

void	check_exit(t_map *map)
{
	size_t	exit_count;

	exit_count = count_element(map->array, EXIT);
	if (exit_count != 1)
	{
		free_map(map);
		error_exit(map_error, g_map_errmsg[exit]);
	}
}

void	check_start(t_map *map)
{
	size_t	start_count;

	start_count = count_element(map->array, START);
	if (exit_count != 1)
	{
		free_map(map);
		error_exit(map_error, g_map_errmsg[start]);
	}
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

void	check_characters(t_map *map, char *valid_chars)
{
	int	i;
	int	j;

	i = 0;
	while (map->array[i])
	{
		j = 0;
		while (map->array[i][j])
		{
			if (!ft_strchr(valid_chars, map->array[i][j]))
			{
				free_map(map);
				error_exit(map_error, g_map_errmsg[characters]);
			}
			j++;
		}
		i++;
	}
}

void	check_wall_enclosed(t_map *map)
{
	size_t	i;

	i = 0;
	while (i < map->width)
	{
		if (map->array[0][i] != WALL || map->array[map->height - 1][i] != WALL)
		{
			free_map(map);
			error_exit(map_error, g_map_errmsg[wall_enclosed]);
		}
		i++;
	}
	i = 1;
	while (i < map->height - 2)
	{
		if (map->array[i][0] != WALL || map->array[i][map->width - 1] != WALL)
		{
			free_map(map);
			error_exit(map_error, g_map_errmsg[wall_enclosed]);
		}
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

void	check_path(t_map *map)
{
	char	**fill_map;

	fill_map = copy_map_array(map);
	flood_fill(fill_map, map->start_y, map->start_x, map);
	if (count_element(fill_map, EXIT) || count_element(fill_map, COLLECTIBLE))
	{
		free_array(fill_map);
		free_map(map);
		error_exit(map_error, g_map_errmsg[valid_path]);
	}
	else
		free_array(fill_map);
}

void	flood_fill(char **array, size_t y, size_t x, t_map *map)
{
	if (y < 0 || y >= map->height || x < 0 || x >= map->width || map_array[y][x]
		== WALL)
		return ;
	else
	{
		array[y][x] = WALL;
		flood_fill(array, y - 1, x, map);
		flood_fill(array, y, x + 1, map);
		flood_fill(array, y + 1, x, map);
		flood_fill(array, y, x - 1, map);
	}
}
		

char	**copy_map_array(t_map *map)
{
	char	**copy;
	size_t	i;

	copy = (char	**)calloc(sizeof(char *) * (map->height + 1));
	if (!copy)
	{
		free_map(map);
		error_exit(system_error, "malloc", NULL);
	}
	while (i < map->height)
	{
		copy[i] = ft_strdup((map->array)[i]);
		if (copy[i])
		{
			free_array(copy);
			free_map(map);
			error_exit(system_error, "malloc", NULL);
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
}/*

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




