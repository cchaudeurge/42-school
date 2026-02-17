
#include "so_long_bonus.h"

void	check_wall_enclosed(t_game *game)
{
	int	i;

	i = 0;
	while (i < game->map.width)
	{
		if (game->map.array[0][i] != WALL || game->map.array[game->map.height - 1][i]
			!= WALL)
			clean_exit(game, EXIT_FAILURE, map_err,
			"Your map must be wall enclosed.");
		i++;
	}
	i = 1;
	while (i < game->map.height - 2)
	{
		if (game->map.array[i][0] != WALL || game->map.array[i][game->map.width
			- 1] != WALL)
			clean_exit(game, EXIT_FAILURE, map_err,
			"Your map must be wall enclosed.");
		i++;
	}
}

void	check_path(t_game *game)
{
	char	**fill_map;

	fill_map = copy_map_array(game);
	flood_fill(fill_map, game->player.pos.y, game->player.pos.x, game);
	if (count_element(fill_map, EXIT) || count_element(fill_map, COLLECTIBLE))
	{
		free_array(fill_map);
		clean_exit(game, EXIT_FAILURE, map_err, "Your map must have a valid path.");
	}
	free_array(fill_map);
}

void	flood_fill(char **array, int y, int x, t_game *game)
{
	if (y < 0 || y >= game->map.height || x < 0 || x >=
		game->map.width || array[y][x] == WALL ||
			array[y][x] == ENEMY || array[y][x] == VISITED)
		return ;
	array[y][x] = VISITED;
	flood_fill(array, y - 1, x, game);
	flood_fill(array, y, x + 1, game);
	flood_fill(array, y + 1, x, game);
	flood_fill(array, y, x - 1, game);
}
		

char	**copy_map_array(t_game *game)
{
	char	**copy;
	int		i;

	copy = (char **)ft_calloc(game->map.height + 1, sizeof(char *));
	if (!copy)
		clean_exit(game, EXIT_FAILURE, sys_err, "malloc");
	i = 0;
	while (i < game->map.height)
	{
		copy[i] = ft_strdup((game->map.array)[i]);
		if (!copy[i])
		{
			free_array(copy);
			clean_exit(game, EXIT_FAILURE, sys_err, "malloc");
		}
		i++;
	}
	return (copy);
}

void	check_extension(t_game *game, char *map_path)
{
	size_t	length;

	length = ft_strlen(map_path);
	if (length > 4 && ft_strncmp(map_path + length - 4, ".ber", 4) == 0)
		return ;
	else
		clean_exit(game, EXIT_FAILURE, map_err, "Map must be a .ber file.");
}
