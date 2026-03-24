/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   lis.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cchaudeu <cchaudeu@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/03/17 15:38:54 by cchaudeu          #+#    #+#             */
/*   Updated: 2026/03/18 12:50:50 by cchaudeu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	flag_longest_lis(t_sorter *sorter)
{
	t_lis	*lis_array;
	int		last_elem_index;
	int		i;
	int		nbr;

	optimize_lis(sorter);
	lis_array = (t_lis *)malloc(sizeof(t_lis) * sorter->nb_qty);
	last_elem_index = fill_lis_array(lis_array, sorter);
	i = last_elem_index;
	sorter->stack_a.max = lis_array[i].nbr;
	while (i != lis_array[i].prev_idx)
	{
		nbr = lis_array[i].nbr;
		sorter->numbers[nbr].lis = true;
		i = lis_array[i].prev_idx;
	}
	nbr = lis_array[i].nbr;
	sorter->stack_a.min = nbr;
	sorter->numbers[nbr].lis = true;
	free (lis_array);
}

/*void	flag_lis_elem(t_lis *array, t_sorter *sorter, int last_elem_index)
{
	int	i;
	int	nbr;

	i = last_elem_index;
	while (i != array[i].prev_idx)
	{
		nbr = array[i].nbr;
		sorter->numbers[nbr].lis = true;
		i = array[i].prev_idx;
	}
	nbr = array[i].nbr;
	sorter->numbers[nbr].lis = true;
}*/

int	fill_lis_array(t_lis *array, t_sorter *sorter)
{
	int	i;
	int	j;

	i = 0;
	while (i < sorter->nb_qty)
	{
		array[i].nbr
			= sorter->stack_a.arr[(sorter->lis_head + i) % sorter->nb_qty];
		array[i].lis = 1;
		array[i].prev_idx = i;
		j = 0;
		while (j < i)
		{
			if (array[j].nbr < array[i].nbr && array[j].lis + 1 >= array[i].lis)
			{
				array[i].lis = array[j].lis + 1;
				array[i].prev_idx = j;
				if (array[i].lis == sorter->lis_len)
					return (i);
			}
			j++;
		}
		i++;
	}
	return (i - 1);
}

void	find_longest_lis(t_sorter *sorter)
{
	int	current_head;
	int	current_lis_len;

	sorter->lis_len = lis_length(sorter->stack_a, 0);
	sorter->lis_head = 0;
	current_head = 1;
	while (current_head < sorter->stack_a.cap)
	{
		current_lis_len = lis_length(sorter->stack_a, current_head);
		if (current_lis_len > sorter->lis_len)
		{
			sorter->lis_len = current_lis_len;
			sorter->lis_head = current_head;
		}
		if (current_lis_len == sorter->stack_a.cap)
			return ;
		current_head++;
	}
}

int	lis_length(t_stack stack, int head)
{
	int	*lis_array;
	int	last;
	int	i;
	int	insertion_idx;

	lis_array = (int *)malloc(sizeof(int) * stack.size);
	lis_array[0] = stack.arr[head];
	last = 0;
	i = (head + 1) % stack.cap;
	while (i != head)
	{
		if (stack.arr[i] > lis_array[last])
		{
			last++;
			lis_array[last] = stack.arr[i];
		}
		else
		{
			insertion_idx = upper_bound_sorted(lis_array, stack.arr[i], last);
			lis_array[insertion_idx] = stack.arr[i];
		}
		i = (i + 1) % stack.cap;
	}
	free (lis_array);
	return (last + 1);
}

int	upper_bound_sorted(int *array, int nbr, int max_index)
{
	int	low;
	int	high;
	int	mid;
	int	upper_bound;

	low = 0;
	high = max_index;
	upper_bound = 0;
	while (low <= high)
	{
		mid = low + (high - low) / 2;
		if (nbr < array[mid])
		{
			upper_bound = mid;
			high = mid - 1;
		}
		else
			low = mid + 1;
	}
	return (upper_bound);
}
