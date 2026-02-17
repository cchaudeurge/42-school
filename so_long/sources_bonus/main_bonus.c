
#include "so_long_bonus.h"

int	main(int argc, char **argv)
{
	t_game	game;

	ft_bzero(&game, sizeof(t_game));
	if (argc != 2)
		clean_exit(&game, EXIT_FAILURE, custom_err,
			"You must provide exactly 1 .ber map to play the game.");
	init_game(&game, argv[1]);
	mlx_hook(game.render.win, 17, 0, exit_game, &game);
	mlx_hook(game.render.win, 2, 1L<<0, key_handler, &game);
	mlx_loop_hook(game.render.mlx, game_loop, &game);
	mlx_loop(game.render.mlx);
	return (0);
}


