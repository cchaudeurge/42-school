#include "so_long_bonus.h"

int	game_loop(void *param)
{
	t_game	*game;
	long	current_time;
	
	game = (t_game *)param;
	if (game->state == won)
		clean_exit(game, EXIT_SUCCESS, no_error, "Congrats! You won!");
	else if (game->state == lost)
		clean_exit(game, EXIT_SUCCESS, no_error, "Boooo! You lost!");
	current_time = get_time_ms();
	if (current_time - game->render.last_anim_update >= 200)
	//game->render.anim_counter = (game->render.anim_counter + 1) % 10000;
	//if (game->render.anim_counter == 0)
	{
		update_animation_frames(game);
		game->render.last_anim_update = current_time;
	}
	else if (game->render.needed == true)
		render_game(game);
	return(0);
}

void	update_animation_frames(t_game *game)
{
	game->render.anim.player = (game->render.anim.player + 1) % PLAYER_FRAMES;
	game->render.anim.coll = (game->render.anim.coll + 1) % COLLECT_FRAMES;
	game->render.anim.exit = (game->render.anim.exit + 1) % EXIT_FRAMES;
	game->render.anim.enemy = (game->render.anim.enemy + 1) % ENEMY_FRAMES;
	render_game(game);
}

void	render_game(t_game *game)
{
	render_environment(game);
	render_player(game);
	render_moves(game);
	game->render.needed = false;
}

long	get_time_ms(void)
{
	struct timeval	tv;

	gettimeofday(&tv, NULL);
	return (tv.tv_sec * 1000 + tv.tv_usec / 1000);
}
