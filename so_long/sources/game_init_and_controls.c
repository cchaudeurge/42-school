
#include "so_long.h"


void	init_game(t_game *game, char *map_path)
{
	parse_init_check_map(game, map_path);
	game->state = playing;
	game->player.moves = 0;
	game->render.mlx = mlx_init();
	if (!game->render.mlx)
		clean_exit(game, EXIT_FAILURE, sys_err, "mlx_init");
	game->render.win = mlx_new_window(game->render.mlx, game->map.width *
	TILE_W,	game->map.height * TILE_H, "so_long");
	if (!game->render.win)
		clean_exit(game, EXIT_FAILURE, sys_err, "mlx_new_window");
	load_all_images(game);
	mlx_set_font(game->render.mlx, game->render.win, "-adobe-courier-bold-r-normal--24-240-75-75-m-150-iso8859-1");
}

int	key_handler(int keycode, void *param)
{
	t_game	*game;

	game = (t_game *)param;
	if (keycode == XK_Escape)
		clean_exit(game, EXIT_SUCCESS, 0, NULL);
	else if (keycode == XK_Left || keycode == XK_a)
		move_player(game, -1, 0, left);
	else if (keycode == XK_Right || keycode == XK_d)
		move_player(game, 1, 0, right);
	else if (keycode == XK_Up || keycode == XK_w)
		move_player(game, 0, -1, up);
	else if (keycode == XK_Down || keycode == XK_s)
		move_player(game, 0, 1, down);
	return (0);
}

void	move_player(t_game *game, int dx, int dy, t_direction direction)
{
	char	target_tile;
	t_pos	target;

	target.x = game->player.pos.x + dx;
	target.y = game->player.pos.y + dy;
	target_tile = game->map.array[target.y][target.x];
	game->player.direction = direction;
	if (target.x < 0 || target.x > game->map.width ||
		target.y < 0 || target.y > game->map.height || target_tile == WALL)
		return ;
	if (target_tile == COLLECTIBLE)
	{
		game->map.collectibles--;
		game->map.array[target.y][target.x] = EMPTY;
		if (game->map.collectibles == 0)
			game->map.exit_is_open = true;
	}
	else if (target_tile == EXIT && game->map.exit_is_open)
		game->state = won;
	game->player.pos = target;
	game->player.moves++;
	game->render.needed = true;
	put_moves(game);
}

void	put_moves(t_game *game)
{
	ft_putstr_fd("Moves: ", 1);
	ft_putnbr_fd(game->player.moves, 1);
	ft_putstr_fd("\n", 1);
}

int	exit_game(void *param)
{
	t_game	*game;

	game = (t_game *)param;
	clean_exit(game, EXIT_SUCCESS, 0, NULL);
	return (0);
}
