#include "so_long.h"

/*void	load_img(t_game *game, t_image image, char *filename)
{	
	image.img_ptr = mlx_xpm_file_to_image(game->render.mlx, filename,
	&image.width, &image.height);
	if (!image.img_ptr)
		clean_exit(game, EXIT_FAILURE, sys_err, "mlx_xpm_file_to_image");
}

void	load_player_imgs(t_game *game)
{
	load_img(game, game->render.player.up[0], "BryceBack1.xpm");
	load_img(game, game->render.player.up[1], "BryceBack2.xpm");
	load_img(game, game->render.player.up[2], "BryceBack3.xpm");
	load_img(game, game->render.player.up[3], "BryceBack4.xpm");
	load_img(game, game->render.player.down[0], "BryceFront1.xpm");
	load_img(game, game->render.player.down[1], "BryceFront2.xpm");
	load_img(game, game->render.player.down[2], "BryceFront3.xpm");
	load_img(game, game->render.player.down[3], "BryceFront4.xpm");
	load_img(game, game->render.player.left[0], "BryceLeft1.xpm");
	load_img(game, game->render.player.left[1], "BryceLeft2.xpm");
	load_img(game, game->render.player.left[2], "BryceLeft3.xpm");
	load_img(game, game->render.player.left[3], "BryceLeft4.xpm");
	load_img(game, game->render.player.right[0], "BryceRight1.xpm");
	load_img(game, game->render.player.right[1], "BryceRight2.xpm");
	load_img(game, game->render.player.right[2], "BryceRight3.xpm");
	load_img(game, game->render.player.right[3], "BryceRight4.xpm");
}

void	load_other_imgs(t_game *game)
{
	load_img(game, game->render.env.wall[0], "wallA.xpm");
	load_img(game, game->render.env.wall[1], "wallB.xpm");
	load_img(game, game->render.env.empty[0], "floorA.xpm");
	load_img(game, game->render.env.empty[1], "floorB.xpm");
	load_img(game, game->render.env.exit[0], "exit1.xpm");
	load_img(game, game->render.env.exit[1], "exit2.xpm");
	load_img(game, game->render.env.exit[2], "exit3.xpm");
	load_img(game, game->render.env.exit[3], "exit4.xpm");
	load_img(game, game->render.collect[0], "coin1.xpm");
	load_img(game, game->render.collect[1], "coin2.xpm");
	load_img(game, game->render.collect[2], "coin3.xpm");
	load_img(game, game->render.collect[3], "coin4.xpm");
}

void	load_enemy_imgs(t_game *game)
{
	load_img(game, game->render.enemy[0], "enemy1.xpm");
	load_img(game, game->render.enemy[1], "enemy2.xpm");
	load_img(game, game->render.enemy[2], "enemy3.xpm");
	load_img(game, game->render.enemy[3], "enemy4.xpm");
}*/

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
}

/*void	load_all_images(t_game *game)
{
	load_player_imgs(game);
	load_other_imgs(game);
	load_enemy_imgs(game);
}*/


