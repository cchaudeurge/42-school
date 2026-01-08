static const char	*g_map_errmsg[conditions_count] = {
	[extension] = "Map must be a .ber file.",
	[characters] = "Your map must only contain the following characters: 0, 1,
	C, E, P.\n",
	[exit] = "Your map must contain exactly one exit.",
	[start] = "Your map must contain exactly one starting position.",
	[collectibles] = "Your map must contain at least one collectible.",
	[shape] = "Your map must be rectangular.",
	[wall_enclosed] = "Your map must be wall enclosed.",
	[valid_path] = "Your map must have a valid path."
}

void error_exit(t_errtype errtype, const char *context)
{
	int	i;

	ft_putendl_fd("Error", 2);
	if (errtype == system_error)
	{
		perror(context);
		exit(EXIT_FAILURE);
	}
	else if (errtype == map_error)
	{
		ft_putendl_fd("Invalid map.", 2);
		i = 0;
		while (i < conditions_count)
		{
			if (!map_conditions[i])
				ft_putendl_fd(g_map_errmsg[i], 2);
			i++;
		}
		exit(EXIT_FAILURE);
	}
	else if (errtype == custom_error)
	{
		ft_putendl_fd(context, 2);
		exit(EXIT_FAILURE);
	}
}

void	free_array(char **map)
{
	int	i;

	i = 0;
	while (map[i])
	{
		free(map[i]);
		i++;
	}
	free(map);
}

void	free_map(t_map *map)
{
	free_array(map->array);
	//need something for conditions array?
	free(map);
}



