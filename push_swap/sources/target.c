/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   target.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cchaudeu <cchaudeu@student.42berlin.d      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/03/17 15:41:42 by cchaudeu          #+#    #+#             */
/*   Updated: 2026/03/17 15:42:18 by cchaudeu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	find_target_idx(int nbr, t_stack *stack)
{
	int	target_value;
	int	target_idx;

	if (nbr > stack->max || nbr < stack->min)
		target_value = stack->min;
	else
		target_value = find_smallest_bigger(nbr, *stack, 0, stack->size - 1);
	target_idx = find_x_idx(target_value, *stack, 0, stack->size - 1);
	return (target_idx);
}

int find_smallest_bigger(int x, t_stack s, int lo, int hi)
{
	int	mi;
	int smallest_bigger_found;

	smallest_bigger_found = -1;
	mi = (find_x_idx(s.max, s, lo, hi) - s.hd + s.cap) % s.cap;
	if (x > s.arr[(s.hd + lo) % s.cap])
		hi = mi;
	else
	{
		smallest_bigger_found = s.arr[(s.hd + lo) % s.cap];
		lo = mi + 1;
	}
	while (lo <= hi)
	{
		mi = lo + (hi - lo) / 2;
		if (x < s.arr[(s.hd + mi) % s.cap])
		{
			smallest_bigger_found = s.arr[(s.hd + mi) % s.cap];
			//hi = mi + 1;
			hi = mi - 1;
		}
		else
			lo = mi + 1;
	}
	return (smallest_bigger_found);
}

int	find_x_idx(int x, t_stack s, int lo, int hi)
{
	int	mi;

	while (lo <= hi)
	{
		mi = lo + (hi - lo) / 2;
		if (x == s.arr[(s.hd + mi) % s.cap])
			return ((s.hd + mi) % s.cap);
		else if (s.arr[(s.hd + mi) % s.cap]	<= s.arr[(s.hd + hi) % s.cap])
		{
			if (s.arr[(s.hd + mi) % s.cap] < x 
				&& x <= s.arr[(s.hd + hi) % s.cap])
				lo = mi + 1;
			else 
				hi = mi - 1;
		}
		else
		{
			if (s.arr[(s.hd + lo) % s.cap] <= x
				&& x < s.arr[(s.hd + mi) % s.cap])
				hi = mi - 1;
			else 
				lo = mi + 1;
		}
	}
	return (-1);
}
