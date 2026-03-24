/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main_bonus.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cchaudeu <cchaudeu@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/03/18 20:17:19 by cchaudeu          #+#    #+#             */
/*   Updated: 2026/03/18 20:24:46 by cchaudeu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "checker_bonus.h"

int	main(int argc, char *argv[])
{
	t_checker	checker;

	if (argc < 2)
		clean_exit(NULL, EXIT_FAILURE, input_error, NULL);
	ft_bzero(&checker, sizeof(t_checker));
	parse(&checker, argc, argv);
	check_moves(&checker);
	clean_exit(&checker, -1, no_error, NULL);
	return (0);
}
