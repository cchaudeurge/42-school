/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cleanup_bonus.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cchaudeu <cchaudeu@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/03/18 20:17:11 by cchaudeu          #+#    #+#             */
/*   Updated: 2026/03/18 20:23:04 by cchaudeu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "checker_bonus.h"

void	clean_exit(t_checker *checker, int exit_code,
	t_errtype errtype, char	*context)
{
	if (checker)
	{
		if (checker->stack_a.arr)
			free(checker->stack_a.arr);
		if (checker->stack_b.arr)
			free(checker->stack_b.arr);
	}
	if (exit_code == EXIT_FAILURE)
	{
		ft_putendl_fd("Error", 2);
		if (errtype == system_error)
			perror(context);
	}
	if (exit_code != -1)
		exit(exit_code);
}
