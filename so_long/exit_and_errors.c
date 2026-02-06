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

//NEED TO CLEAN!
/*void error_exit(t_errtype errtype, const char *context)
{
	int	i;

	ft_putendl_fd("Error", 2);
	if (errtype == sys_err)
	{
		perror(context);
		exit(EXIT_FAILURE);
	}
	else if (errtype == map_err)
	{
		ft_putendl_fd("Invalid map.", 2);
		//i = 0;
		//while (i < conditions_count)
		//{
			if (!map_conditions[i])
				ft_putendl_fd(g_map_errmsg[i], 2);
			i++;
		}
		exit(EXIT_FAILURE);
	}
	else if (errtype == custom_err)
	{
		ft_putendl_fd(context, 2);
		exit(EXIT_FAILURE);
	}
}*/

void puterror(t_errtype errtype, const char *context)
{
	ft_putendl_fd("Error", 2);
	if (errtype == sys_err)
		perror(context);
	else if (errtype == map_err)
	{
		ft_putendl_fd("Invalid map.", 2);
		ft_putendl_fd(context, 2);
	}
	else if (errtype == custom_err)
		ft_putendl_fd(context, 2);
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

/*void	free_map(t_map *map)
{
	free_array(map->array);
	//need something for conditions array?
	free(map);
}*/

void	free_img(void *mlx, t_img image)
{
	if (image.img_ptr)
		mlx_destroy_image(mlx, image.img_ptr);
}

void	free_all_images(t_game *game)
{
	int	i;

	i = 0;
	while (i <= 3)
	{
		free_img(game->render.mlx, game->render.player.up[i]);
		free_img(game->render.mlx, game->render.player.down[i]);
		free_img(game->render.mlx, game->render.player.left[i]);
		free_img(game->render.mlx, game->render.player.right[i]);
		free_img(game->render.mlx, game->render.environment.exit[i]);
		free_img(game->render.mlx, game->render.collectible[i]);
		free_img(game->render.mlx, game->render.enemy[i]);
		i++;
	}
	free_img(game->render.mlx, game->render.environment.wall[0]);
	free_img(game->render.mlx, game->render.environment.wall[1]);
	free_img(game->render.mlx, game->render.environment.empty[0]);
	free_img(game->render.mlx, game->render.environment.empty[1]);
}

void	clean_ exit(t_game *game, int exit_code, t_errtype errtype, const char *errcontext)
{
	if (game->map.array)
		free_array(game->map.array);
	if (game->render.mlx)
	{
		free_all_images(game);
		if (game->render.win)
			mlx_destroy_window(game->render.win);
		mlx_destroy_display(game->render.mlx);
		free(game->render.mlx);
	}
	if (exit_code == EXIT_FAILURE)
		puterror(errtype, errcontext);
	exit(exit_code);
}
