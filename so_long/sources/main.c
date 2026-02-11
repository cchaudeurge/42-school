/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cchaudeu <cchaudeu@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/21 17:24:05 by cchaudeu          #+#    #+#             */
/*   Updated: 2025/10/21 21:38:18 by cchaudeu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

int	main(int argc, char **argv)
{
	t_game	game;

	if (argc != 2)
		clean_exit(&game, EXIT_FAILURE, custom_err,
			"You must provide exactly 1 .ber map to play the game.");
	init_game(&game, argv[1]);
	mlx_hook(game.render.win, 17, 0, exit_game, &game);
	mlx_key_hook(game.render.win, key_handler, &game);
	mlx_loop_hook(game.render.mlx, render_game, &game);
	mlx_loop(game.render.mlx);
	return (0);
}


