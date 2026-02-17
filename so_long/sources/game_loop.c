#include "so_long.h"

int	game_loop(void *param)
{
	t_game	*game;
	
	game = (t_game *)param;
	if (game->state == won)
		clean_exit(game, EXIT_SUCCESS, no_error, "Congrats! You won!");
	game->render.anim_counter = (game->render.anim_counter + 1) % 1000;
	if (game->render.anim_counter == 0)
		update_animation_frames(game);
	if (game->render.anim_counter == 0 || game->render.needed == true)
		render_game(game);
	return(0);
}

void	update_animation_frames(t_game *game)
{
	game->render.anim.player = (game->render.anim.player + 1) % PLAYER_FRAMES;
	game->render.anim.coll = (game->render.anim.coll + 1) % COLLECT_FRAMES;
	game->render.anim.exit = (game->render.anim.exit + 1) % EXIT_FRAMES;
}

void	render_game(t_game *game)
{
	render_environment(game);
	render_player(game);
	render_moves(game);
	game->render.needed = false;
}
