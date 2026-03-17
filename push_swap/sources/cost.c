/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cost.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cchaudeu <cchaudeu@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/03/17 15:35:45 by cchaudeu          #+#    #+#             */
/*   Updated: 2026/03/17 18:41:00 by cchaudeu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	find_cheapest(t_sorter *sorter)
{
	t_cost	cost;
	int		i;
	int		idx;

	calculate_cost(sorter->stack_b.hd, &sorter->cheapest_to_a, sorter);
	i = 1;
	while (i <= sorter->cheapest_to_a.c2a && i <= sorter->stack_b.size / 2)
	{
		idx = (sorter->stack_b.hd + i) % sorter->stack_b.cap;
		calculate_cost(idx, &cost, sorter);
		if (cost.c2a <= sorter->cheapest_to_a.c2a)
			sorter->cheapest_to_a = cost;
		idx = (sorter->stack_b.hd + sorter->stack_b.size - i)
			% sorter->stack_b.cap;
		calculate_cost(idx, &cost, sorter);
		if (cost.c2a <= sorter->cheapest_to_a.c2a)
			sorter->cheapest_to_a = cost;
		i++;
	}
}

void	calculate_cost(int b_idx, t_cost *cost, t_sorter *sorter)
{
	int	a_idx;
	int	altc2t;

	a_idx = find_target_idx(sorter->stack_b.arr[b_idx], &sorter->stack_a);
	cost->a_rot = cheapest_c2t(a_idx, sorter->stack_a);
	cost->b_rot = cheapest_c2t(b_idx, sorter->stack_b);
	cost->r_rot = 0;
	if (cost->a_rot * cost->b_rot >= 0)
		cost->c2a = ft_max_abs(cost->a_rot, cost->b_rot);
	else
	{
		cost->c2a = ft_abs(cost->a_rot) + ft_abs(cost->b_rot);
		altc2t = alternate_c2t(cost->a_rot, sorter->stack_a);
		if (ft_max_abs(altc2t, cost->b_rot) < cost->c2a)
		{
			cost->c2a = ft_max_abs(altc2t, cost->b_rot);
			cost->a_rot = altc2t;
		}
		altc2t = alternate_c2t(cost->b_rot, sorter->stack_b);
		if (ft_max_abs(altc2t, cost->a_rot) < cost->c2a)
		{
			cost->c2a = ft_max_abs(altc2t, cost->a_rot);
			cost->b_rot = altc2t;
		}
	}
}

int	alternate_c2t(int c2t, t_stack stack)
{
	int	alt_c2t;

	alt_c2t = -((c2t / ft_abs(c2t)) * (stack.size - ft_abs(c2t)));
	return (alt_c2t);
}

int	cheapest_c2t(int idx, t_stack stack)
{
	int	dist_to_head;

	dist_to_head = (idx - stack.hd + stack.cap) % stack.cap;
	if (dist_to_head <= stack.size / 2)
		return (dist_to_head);
	else
		return (-(stack.size - dist_to_head));
}
