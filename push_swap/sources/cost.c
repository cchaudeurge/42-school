#include "push_swap.h"

void	find_cheapest(t_sorter *sorter)
{
	t_cost	cost;
	int		i;
	int		idx;

//	ft_bzero(&sorter->cheapest_to_a, sizeof(t_cost));
	calculate_cost(sorter->stack_b.hd, &sorter->cheapest_to_a, sorter);
	i = 1;
	while (i <= sorter->cheapest_to_a.c2a && i <= sorter->stack_b.size / 2)
	{
//		ft_bzero(&cost, sizeof(t_cost));
		idx = (sorter->stack_b.hd + i) % sorter->stack_b.cap;
		calculate_cost(idx, &cost, sorter);
		if (cost.c2a <= sorter->cheapest_to_a.c2a)
			sorter->cheapest_to_a = cost;
			//need pointer above?
		idx = (sorter->stack_b.hd + sorter->stack_b.size - i)
			% sorter->stack_b.cap;
		calculate_cost(idx, &cost, sorter);
		if (cost.c2a <= sorter->cheapest_to_a.c2a)
			sorter->cheapest_to_a = cost;
			//need pointer above?
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
	int alt_c2t;

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



/*version with two separate functions
void	calculate_cost(int b_idx, t_cost *cost, t_sorter *sorter)
{
	int	a_idx;

	a_idx = find_target_idx(sorter->stack_b.arr[b_idx], sorter->stack_a);
	cost->a_rot = cheapest_c2t(a_idx, sorter->stack_a);
	cost->b_rot = cheapest_c2t(b_idx, sorter->stack_b);
	cheapest_way_to_a(cost, *sorter);
}

void cheapest_way_to_a(t_cost *cost, t_sorter sorter)
{
	int	a_altc2t;
	int	b_altc2t;

	if (cost->a_rot * cost->b_rot >= 0)
		cost->c2a = ft_max_abs(cost->a_rot, cost->b_rot);
	else
	{
		cost->c2a = ft_abs(a_c2t) + ft_abs(b_c2t);
		a_altc2t = alternate_c2t(cost->a_rot, sorter.stack_a);
		b_altc2t = alternate_c2t(cost->b_rot, sorter.stack_b);
		if (ft_max_abs(a_altc2t, cost->b_rot) < cost->c2a)
		{
			cost->c2a = ft_max_abs(a_altc2t, cost->b_rot);
			cost->a_rot = a_altc2t;
		}
		if (ft_max_abs(b_altc2t, cost->a_rot) < cost->c2a)
		{
			cost->c2a = ft_max_abs(b_altc2t, cost->a_rot);
			cost->b_rot = b_altc2t;
		}
	}
}*/

/*int	find_nbr_idx(int nb, t_stack *stack, int hd, int cap)
{
	int	*arr;
	int	lo;
	int	hi;
	int	mid;

	arr = stack->arr;
	lo = 0;
	hi = stack->size - 1;
	while (lo <= hi)
	{
		mid = lo + (hi - lo) / 2;
		if (nb = arr[(hd + mid) % cap])
			return ((hd + mid) % cap);
		else if (arr[(hd + mid) % cap] <= arr[(hd + hi) % cap])
		{
			if (arr[(hd + mid) % cap] < nb && nb <= arr[(hd + hi) % cap])
				lo = mid + 1;
			else 
				hi = mid - 1;
		}
		else
		{
			if (arr[(hd + lo) % cap] <= nb && nb < arr[(hd + mid) % cap])
				hi = mid - 1;
			else 
				lo = mid + 1;
		}
	}
	return (-1);
}*/
