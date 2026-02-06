void	init_game(t_game *game,	char *map_path)
{
	parse_init_check_map(game, map_path);
	game->state = 0;
	game->player.x = game->map.start_x;
	game->player.y = game->map.start_y;
	game->player.moves = 0;
	game->render.mlx = mlx_init();
	if (!game->render.mlx)
		clean_exit(game, EXIT_FAILURE, sys_err, "mlx_init");
	game->render.win = mlx_new_window(game->render.mlx, game->map.width,
	game->map.height, "so_long");
	if (!game->render.win)
		clean_exit(game, EXIT_FAILURE, sys_err, "mlx_new_window");
	load_all_images(game);
}

int	key_handler(int keycode, void *param)
{
	t_game	*game;
	t_pos	target;

	game = (t_game *)param;
	target = game->player.pos;
	if (keycode == KEY_ESC)
		clean_exit(game, EXIT_SUCCESS, 0, NULL);
	else if (keycode == KEY_LEFT || keycode == KEY_A)
		target.x--;
	else if (keycode == KEY_RIGHT || keycode == KEY_D)
		target.x++;
	else if (keycode == KEY_UP || keycode == KEY_W)
		target.y--;
	else if (keycode == KEY_DOWN || keycode == KEY_S)
		target.y++;
	move_player(game, target);
	return (0);
}

void	move_player(t_game *game, t_pos target)
{
	char	target_tile;

	target_tile = game->map.array[target.y][target.x];
	if (target.x < 0 || target.x > game->map.width || target.y < 0 || target.y >
		game->map.height)
		return ;
	if (target_tile == WALL || (target_tile == EXIT && game->map.collectibles))
		return ;
	if (target_tile == COLLECTIBLE)
	{
		game->map.collectibles--;
		game->map.array[target.y][target.x] = EMPTY;
	}
	else if (target_tile == EXIT && !game->map.collectibles)
		game->state = WON;
	game->player.pos = target;
	game->player.moves++;
}

int	exit_game(void *param)
{
	t_game	*game;

	game = (t_game *)param;
	clean_exit(game, EXIT_SUCCESS, 0, NULL);
	return (0);
}

void	render_moves(t_game *game)
{
	char	*moves;

	moves = ft_itoa(game->player.moves);
	mlx_string_put(game->render.mlx, game->render.win, 10, 10, "Moves: ");
	mlx_string_put(game->render.mlx, game->render.win, 70, 10, moves);
	free(moves);
}

void	render_background(t_game *game)
{
	int	x;
	int	y;

	y = 0;
	while (y <= game->map.height)
	{
		x = 0;
		while (x <= game->map.width)
		{
			mlx_put_image_to_window(game->render.mlx, game->render.win,
			game.render.environment.empty[(x + y) % 2], x * TILE_W , y *
			TILE_H);
			x++;
		}
		y++;
	}
}

void	render_wall(t_game *game)
{
	int	x;
	int	y;

	y = 0;
	while (y <= game->map.height)
	{
		x = 0;
		while (x <= game->map.width)
		{
			if (game->map.array[y][x] == WALL)
				mlx_put_image_to_window(game->render.mlx, game->render.win,
					game.render.environment.wall[(x + y) % 2], x * TILE_W , y *
						TILE_H);
			x++;
		}
		y++;
	}
}


void	render_wall(t_game *game)
{
	t_game	*game;

	game = (t_game *)param;
	ft_printf("Moves: %d", game->player.moves);
	if (game->status == WON)
		render_won(game);
	render_background(game);
	render_wall(game);
	return(0);
}
	
void	render_won(t_game *game)
{
}


