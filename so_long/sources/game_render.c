
#include "so_long.h"

void	render_environment(t_game *game)
{
	int	x;
	int	y;
	void	*img;

	y = 0;
	while (y < game->map.height)
	{
		x = 0;
		while (x < game->map.width)
		{
			img = game->render.env.empty[(x + y) % EMPTY_FRAMES].img_ptr;
			mlx_put_image_to_window(game->render.mlx, game->render.win,
				img, x * TILE_W , y * TILE_H);
			render_non_empty_env_tile(game, x, y);
			x++;
		}
		y++;
	}
}

void	render_non_empty_env_tile(t_game *game, int x, int y)
{
	char	tile;
	void	*img;

	tile = game->map.array[y][x];
	if (tile == WALL)
		img = game->render.env.wall[(x + y) % WALL_FRAMES].img_ptr;
	else if (tile == COLLECTIBLE)
		img = game->render.env.coll[game->render.anim.coll].img_ptr;
	else if (tile == EXIT && game->map.exit_is_open)
		img = game->render.env.exit[game->render.anim.exit].img_ptr;
	else
		return;
	mlx_put_image_to_window(game->render.mlx, game->render.win,	img,
		x * TILE_W , y * TILE_H);
}

void	render_player(t_game *game)
{
	void	*img;
	int		frame;
	
	frame = game->render.anim.player;
	if (game->player.direction == down)
		img = game->render.player.down[frame].img_ptr;
	else if (game->player.direction == up)
		img = game->render.player.up[frame].img_ptr;
	else if (game->player.direction == left)
		img = game->render.player.left[frame].img_ptr;
	else if (game->player.direction == right)
		img = game->render.player.right[frame].img_ptr;
	mlx_put_image_to_window(game->render.mlx, game->render.win,
			img, game->player.pos.x * TILE_W, game->player.pos.y * TILE_H);
}	

void	render_moves(t_game *game)
{
	char	*moves;

	moves = ft_itoa(game->player.moves);
	mlx_string_put(game->render.mlx, game->render.win, 32, (game->map.height *
	TILE_H) - 25, 0xFFFFFF, "Moves: ");
	mlx_string_put(game->render.mlx, game->render.win, 130, (game->map.height *
	TILE_H) - 25, 0xFFFFFF, moves);
	free(moves);
}
