#include "so_long_bonus.h"

char	*build_path(t_game *game, char *base, int frame_num)
{
	char	*frame_str;
	char	*temp;
	char	*path;

	frame_str = ft_itoa(frame_num);
	if (!frame_str)
		clean_exit(game, EXIT_FAILURE, sys_err, "malloc");
	temp = ft_strjoin(base, frame_str);
	if (!temp)
	{
		free(frame_str);
		clean_exit(game, EXIT_FAILURE, sys_err, "malloc");
	}
	path = ft_strjoin(temp, EXTENSION);
	if (!path)
	{
		free(frame_str);
		free(temp);
		clean_exit(game, EXIT_FAILURE, sys_err, "malloc");
	}
	free(frame_str);
	free(temp);
	return (path);
}

void	load_frames(t_game *game, t_img *frames, char *base, int count)
{
	int		i;
	char	*path;

	i = 0;
	while (i < count)
	{
		path = build_path(game, base, i);
		frames[i].img_ptr = mlx_xpm_file_to_image(game->render.mlx, path,
			&frames[i].width, &frames[i].height);
		free(path);
		if (!frames[i].img_ptr)
			clean_exit(game, EXIT_FAILURE, sys_err, "mlx_xpm_file_to_image");
		i++;
	}
}

void	load_all_images(t_game *game)
{
	load_frames(game, game->render.player.up, PL_UP_BASE, PLAYER_FRAMES);
	load_frames(game, game->render.player.down, PL_DOWN_BASE, PLAYER_FRAMES);
	load_frames(game, game->render.player.left, PL_LEFT_BASE, PLAYER_FRAMES);
	load_frames(game, game->render.player.right, PL_RIGHT_BASE, PLAYER_FRAMES);
	load_frames(game, game->render.env.coll, COLLECT_BASE, COLLECT_FRAMES);
	load_frames(game, game->render.env.exit, EXIT_BASE, EXIT_FRAMES);
	load_frames(game, game->render.env.wall, WALL_BASE, WALL_FRAMES);
	load_frames(game, game->render.env.empty, EMPTY_BASE, EMPTY_FRAMES);
	load_frames(game, game->render.env.enem, ENEMY_BASE, ENEMY_FRAMES);
}
