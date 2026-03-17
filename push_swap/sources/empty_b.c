/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   empty_b.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cchaudeu <cchaudeu@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/03/17 15:37:56 by cchaudeu          #+#    #+#             */
/*   Updated: 2026/03/17 18:40:57 by cchaudeu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	min_a_to_top(t_sorter *sorter)
{
	int	min_idx;
	int	rot_count;

	min_idx = find_x_idx(0, sorter->stack_a, 0, sorter->stack_a.size - 1);
	rot_count = cheapest_c2t(min_idx, sorter->stack_a);
	if (rot_count < 0)
		move(sorter, ft_abs(rot_count), revrotate, stack_a);
	else if (rot_count > 0)
		move(sorter, ft_abs(rot_count), rotate, stack_a);
}

void	empty_b(t_sorter *sorter)
{
	while (sorter->stack_b.size > 0)
	{
		find_cheapest(sorter);
		if (sorter->cheapest_to_a.a_rot * sorter->cheapest_to_a.b_rot
			> 0)
			optimize_rotations(&sorter->cheapest_to_a);
		move_cheapest(sorter);
	}
}

void	move_cheapest(t_sorter *sorter)
{
	int	i;

	if (sorter->cheapest_to_a.a_rot < 0)
	{
		i = ft_abs(sorter->cheapest_to_a.a_rot);
		move(sorter, i, revrotate, stack_a);
	}
	i = ft_abs(sorter->cheapest_to_a.r_rot);
	if (sorter->cheapest_to_a.r_rot < 0)
		move(sorter, i, revrotate, both_ab);
	else if (sorter->cheapest_to_a.r_rot > 0)
		move(sorter, i, rotate, both_ab);
	i = ft_abs(sorter->cheapest_to_a.b_rot);
	if (sorter->cheapest_to_a.b_rot < 0)
		move(sorter, i, revrotate, stack_b);
	else if (sorter->cheapest_to_a.b_rot > 0)
		move(sorter, i, rotate, stack_b);
	if (sorter->cheapest_to_a.a_rot > 0)
	{
		i = ft_abs(sorter->cheapest_to_a.a_rot);
		move(sorter, i, rotate, stack_a);
	}
	move(sorter, 1, push, stack_a);
}

void	optimize_rotations(t_cost *cost)
{
	if (ft_abs(cost->a_rot) >= ft_abs(cost->b_rot))
	{
		cost->r_rot = cost->b_rot;
		cost->a_rot -= cost->b_rot;
		cost->b_rot = 0;
	}
	else
	{
		cost->r_rot = cost->a_rot;
		cost->b_rot -= cost->a_rot;
		cost->a_rot = 0;
	}
}
