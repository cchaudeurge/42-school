
#include "so_long.h"

void	render_moves(t_game *game)
{
	char	*moves;

	moves = ft_itoa(game->player.moves);
	mlx_string_put(game->render.mlx, game->render.win, 10, 10, 0xFFFFFF, "Moves: ");
	mlx_string_put(game->render.mlx, game->render.win, 70, 10, 0xFFFFFF, moves);
	free(moves);
}

/*void	render_background(t_game *game)
{
	int	x;
	int	y;

	y = 0;
	while (y < game->map.height)
	{
		x = 0;
		while (x < game->map.width)
		{
			mlx_put_image_to_window(game->render.mlx, game->render.win,
			game->render.environment.empty[(x + y) % 2].img_ptr, x * TILE_W , y * TILE_H);
			x++;
		}
		y++;
	}
}*/

/*void	render_wall(t_game *game)
{
	int	x;
	int	y;

	y = 0;
	while (y < game->map.height)
	{
		x = 0;
		while (x < game->map.width)
		{
			if (game->map.array[y][x] == WALL)
				mlx_put_image_to_window(game->render.mlx, game->render.win,
					game->render.environment.wall[(x + y) % 2].img_ptr, x * TILE_W , y * TILE_H);
			x++;
		}
		y++;
	}
}*/

/*XXXXXXChange back to ft_printf!!!*/

/*void	render_environment(t_game *game)
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
			if (game->map.array[y][x] == WALL)
				img = game->render.env.wall[(x + y) % WALL_FRAMES].img_ptr;
			else if (game->map.array[y][x] == COLLECTIBLE)
				img = game->render.env.coll[game->render.anim.coll].img_ptr;
			mlx_put_image_to_window(game->render.mlx, game->render.win,
					img, x * TILE_W , y * TILE_H);
			x++;
		}
		y++;
	}
}*/

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
	else if (tile == EXIT && game->exit_state == OPEN)
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
	if (game->player.direction == DOWN)
		img = game->render.player.down[frame].img_ptr;
	else if (game->player.direction == UP)
		img = game->render.player.up[frame].img_ptr;
	else if (game->player.direction == LEFT)
		img = game->render.player.left[frame].img_ptr;
	else if (game->player.direction == RIGHT)
		img = game->render.player.right[frame].img_ptr;
	mlx_put_image_to_window(game->render.mlx, game->render.win,
			img, game->player.pos.x * TILE_W, game->player.pos.y * TILE_H);
}	
	

void	render_game(t_game *game)
{
	render_environment(game);
	render_player(game);
	render_moves(game);
	game->render.needed == FALSE;
}
	

void	update_animation_frames(game)
{
	game->render.anim.player = (game->render.anim.player + 1) % PLAYER_FRAMES;
	game->render.anim.coll = (game->render.anim.coll + 1) % COLLECT_FRAMES;
	game->render.anim.exit = (game->render.anim.exit + 1) % EXIT_FRAMES;
}

int	game_loop(void *param)
{
	t_game	*game;
	
	game = (t_game *)param;
	game->render.anim_counter = (game->render.anim_counter + 1) % 10;
	if (game->render.anim_counter == 0)
		update_animation_frames(game);
	if (game->render.anim_counter == 0 || game->render.needed == TRUE)
		render_game(game);
	return(0);
}
