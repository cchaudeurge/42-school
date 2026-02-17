#include "so_long_bonus.h"

void puterror(t_errtype errtype, char *context)
{
	ft_putendl_fd("Error", 2);
	if (errtype == sys_err)
		perror(context);
	else if (errtype == map_err)
	{
		ft_putendl_fd("Invalid map.", 2);
		ft_putendl_fd(context, 2);
	}
	else if (errtype == custom_err)
		ft_putendl_fd(context, 2);
}

void	free_array(char **map)
{
	int	i;

	i = 0;
	while (map[i])
	{
		free(map[i]);
		i++;
	}
	free(map);
}

void	free_img(void *mlx, t_img image)
{
	if (image.img_ptr)
		mlx_destroy_image(mlx, image.img_ptr);
}

void	free_all_images(t_game *game)
{
	int	i;

	i = 0;
	while (i <= 3)
	{
		free_img(game->render.mlx, game->render.player.up[i]);
		free_img(game->render.mlx, game->render.player.down[i]);
		free_img(game->render.mlx, game->render.player.left[i]);
		free_img(game->render.mlx, game->render.player.right[i]);
		free_img(game->render.mlx, game->render.env.exit[i]);
		free_img(game->render.mlx, game->render.env.coll[i]);
		free_img(game->render.mlx, game->render.env.enem[i]);
		i++;
	}
	free_img(game->render.mlx, game->render.env.wall[0]);
	free_img(game->render.mlx, game->render.env.wall[1]);
	free_img(game->render.mlx, game->render.env.empty[0]);
	free_img(game->render.mlx, game->render.env.empty[1]);
}

void	clean_exit(t_game *game, int exit_code, t_errtype errtype, char *errcontext)
{
	if (game && game->map.array)
		free_array(game->map.array);
	if (game && game->render.mlx)
	{
		free_all_images(game);
		if (game && game->render.win)
			mlx_destroy_window(game->render.mlx, game->render.win);
		mlx_destroy_display(game->render.mlx);
		free(game->render.mlx);
	}
	if (exit_code == EXIT_FAILURE)
		puterror(errtype, errcontext);
	else if (errtype == no_error)
		ft_putendl_fd(errcontext, 1);
	exit(exit_code);
}
