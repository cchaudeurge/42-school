/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cleanup.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cchaudeu <cchaudeu@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/03/17 15:35:05 by cchaudeu          #+#    #+#             */
/*   Updated: 2026/03/17 18:35:01 by cchaudeu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	clean_exit(t_sorter *sorter, int exit_code, t_errtype errtype,
			char *context)
{
	if (sorter)
	{
		if (sorter->numbers)
			free(sorter->numbers);
		if (sorter->stack_a.arr)
			free(sorter->stack_a.arr);
		if (sorter->stack_b.arr)
			free(sorter->stack_b.arr);
		if (sorter->move_lst)
			ft_lstclear(&sorter->move_lst, free);
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
