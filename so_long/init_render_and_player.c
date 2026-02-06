void	init_render(t_game *game)
{
	game->render.mlx = mlx_init();
	if (!game->render.mlx)
		clean_exit(game, EXIT_FAILURE, sys_err, "mlx_init");
	game->render.win = mlx_new_window(game->render.mlx, game->map.width *
	TILE_W, game->map.height * TILE_H, "so_long");
	if (!game->render.win)
		clean_exit(game, EXIT_FAILURE, sys_err, "mlx_new_window");
}

void	init_player(t_game *game)
{
	game->player.x = game->map.start_x;
	game->player.y = game->map.start_y;
	game->player.moves = 0;
}

