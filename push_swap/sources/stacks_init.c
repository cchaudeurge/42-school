/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   stacks_init.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cchaudeu <cchaudeu@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/03/17 15:41:13 by cchaudeu          #+#    #+#             */
/*   Updated: 2026/03/18 19:09:49 by cchaudeu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	create_and_fill_stacks(t_sorter *sorter)
{
	int		issorted;
	size_t	stack_size;
	int		i;
	int		idx;

	issorted = bubble_sort(sorter->numbers, sorter->nb_qty);
	if (issorted)
		clean_exit(sorter, EXIT_SUCCESS, no_error, NULL);
	stack_size = (size_t)sorter->nb_qty;
	sorter->stack_a.arr = (int *)malloc(stack_size * sizeof(int));
	sorter->stack_b.arr = (int *)malloc(stack_size * sizeof(int));
	if (!sorter->stack_a.arr || !sorter->stack_b.arr)
		clean_exit(sorter, EXIT_FAILURE, system_error, "malloc");
	sorter->stack_b.cap = sorter->nb_qty;
	i = 0;
	while (i < sorter->nb_qty)
	{
		idx = sorter->numbers[i].index;
		sorter->stack_a.arr[idx] = i;
		i++;
	}
	sorter->stack_a.hd = 0;
	sorter->stack_a.size = i;
	sorter->stack_a.cap = i;
}

/*Sorts the initial arr so the values can be normalized by their sorted index.
 * Returns 0 if it sorted something, and 1 otherwise (i.e.: if the numbers were
 * already sorted).*/

int	bubble_sort(t_number *numbers, int size)
{
	int			i;
	int			j;
	int			issorted;
	t_number	buffer;

	issorted = 1;
	j = 0;
	while (size - j >= 2)
	{
		i = 0;
		while (i + 1 < size - j)
		{
			if (numbers[i].value > numbers [i + 1].value)
			{
				issorted = 0;
				buffer = numbers[i];
				numbers[i] = numbers[i + 1];
				numbers[i + 1] = buffer;
			}
			i++;
		}
		j++;
	}
	return (issorted);
}

void	fill_stack_b(t_sorter *sorter)
{
	int	i;
	int	nbr;

	while (sorter->stack_a.size > sorter->lis_len)
	{
		if (cheap_insert_from_b_into_lis(sorter))
			move(sorter, 1, rotate, stack_a);
		else
		{
			i = sorter->stack_a.hd;
			nbr = sorter->stack_a.arr[i];
			if (sorter->numbers[nbr].lis == true)
			{
				move(sorter, 1, rotate, stack_a);
			}
			else
			{
				move(sorter, 1, push, stack_b);
				if (sorter->nb_qty >= 120 && nbr < (sorter->nb_qty / 2)
					&& sorter->stack_b.arr[(sorter->stack_b.hd + 1)
						% sorter->stack_b.cap] > (sorter->nb_qty / 2))
					move(sorter, 1, rotate, stack_b);
			}
		}
	}
}
/*Complex*/
// if (nbr < (sorter->nb_qty / 2) &&
// 					sorter->stack_b.arr[(sorter->stack_b.hd + 1) %
// 					sorter->stack_b.cap] > (sorter->nb_qty / 2))
/*Medium*/
// if (nbr > (sorter->nb_qty / 2) &&
// 					sorter->stack_b.arr[(sorter->stack_b.hd + 1) %
// 					sorter->stack_b.cap] < (sorter->nb_qty / 2))
// 					move(sorter, 1, rotate, stack_b);

int	cheap_insert_from_b_into_lis(t_sorter *s)
{
	int		nb;
	int		fa;
	int		la;

	if (s->stack_b.size == 0)
		return (0);
	nb = s->stack_b.arr[s->stack_b.hd];
	fa = s->stack_a.arr[s->stack_a.hd];
	la = s->stack_a.arr[(s->stack_a.hd + s->stack_a.size - 1) % s->stack_a.cap];
	if (!s->numbers[fa].lis || !s->numbers[la].lis)
		return (0);
	if ((nb < fa && (nb > la || la > fa)) || (nb > fa && nb > la && fa < la))
	{
		move(s, 1, push, stack_a);
		return (1);
	}
	nb = s->stack_b.arr[(s->stack_b.hd + s->stack_b.size - 1) % s->stack_b.cap];
	if ((nb < fa && (nb > la || la > fa)) || (nb > fa && nb > la && fa < la))
	{
		move(s, 1, revrotate, stack_b);
		move(s, 1, push, stack_a);
		return (1);
	}
	return (0);
}
