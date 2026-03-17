/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cchaudeu <cchaudeu@student.42berlin.d      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/03/17 15:40:48 by cchaudeu          #+#    #+#             */
/*   Updated: 2026/03/17 15:40:57 by cchaudeu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	push_swap(int argc, char *argv[])
{
	t_sorter	sorter;
	
	ft_bzero(&sorter, sizeof(t_sorter));
	parse(&sorter, argc, argv);
	create_and_fill_stacks(&sorter);
	flag_longest_lis(&sorter);
	fill_stack_b(&sorter);
	empty_b(&sorter);
	min_a_to_top(&sorter);
	optimize_s_s(sorter.move_lst);
	optimize_r_rr(sorter.move_lst);
	optimize_pa_pb(sorter.move_lst);
	optimize_ra_pa_rra(&sorter, sorter.move_lst);
	put_move_lst(sorter.move_lst);
	clean_exit(&sorter, -1, no_error, NULL);
}
