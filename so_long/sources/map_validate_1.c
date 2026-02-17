
#include "so_long.h"

void	check_map(t_game *game)
{
	check_characters(game, VALID_CHARSET);
	check_exit_and_start(game);
	if (!game->map.collectibles)
		clean_exit(game, EXIT_FAILURE, map_err, "Your map must contain at least one collectible.");
	check_shape(game);
	check_wall_enclosed(game);
	check_path(game);
}

void	check_characters(t_game *game, char *valid_chars)
{
	int	i;
	int	j;

	i = 0;
	while (game->map.array[i])
	{
		j = 0;
		while (game->map.array[i][j])
		{
			if (!ft_strchr(valid_chars, game->map.array[i][j]))
				clean_exit(game, EXIT_FAILURE, map_err,
				"Your map must only contain the following characters: 0, 1, C, E, P.");
			j++;
		}
		i++;
	}
}

void	check_exit_and_start(t_game *game)
{
	size_t	exit_count;
	size_t	start_count;

	exit_count = count_element(game->map.array, EXIT);
	if (exit_count != 1)
		clean_exit(game, EXIT_FAILURE, map_err, "Your map must contain exactly one exit.");
	start_count = count_element(game->map.array, START);
	if (start_count != 1)
		clean_exit(game, EXIT_FAILURE, map_err, "Your map must contain exactly one starting position.");
}

void	check_shape(t_game *game)
{
    int		i;
	int		length;

    i = 0;
    while (i < game->map.height)
    {
        length = (int)ft_strlen(game->map.array[i]);
		if (length != game->map.width)
			clean_exit(game, EXIT_FAILURE, map_err, "Your map must be rectangular.");
        i++;
    }
}

size_t	count_element(char **map, char element)
{
	size_t	element_count;
	int	i;

	element_count = 0;
	i = 0;
	while (map[i])
	{
		element_count += ft_charcount(map[i], element);
		i++;
	}
	return (element_count);
}
