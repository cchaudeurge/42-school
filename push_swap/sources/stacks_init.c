#include "push_swap.h"

void	create_move_lst(t_sorter *sorter)
{
	sorter->move_lst = (t_list *)ft_calloc(1, sizeof(t_list));
	if (!sorter->move_lst)
		clean_exit(sorter, EXIT_FAILURE, system_error, "malloc");
}

void	create_and_fill_stacks(t_sorter *sorter)
{
//	int		issorted;
	size_t	stack_size;
	int		i;
	int		idx;

/*	issorted =*/ bubble_sort(sorter->numbers, sorter->nb_qty);
/*	if (issorted)
	{
		clean_exit(sorter, EXIT_SUCCESS, no_error, NULL);
	}*/
	stack_size = (size_t)sorter->nb_qty;
	sorter->stack_a.arr = (int *)malloc(stack_size * sizeof(int));
	sorter->stack_b.arr = (int *)malloc(stack_size * sizeof(int));
	if (!sorter->stack_a.arr || !sorter->stack_b.arr)
		clean_exit(sorter, EXIT_FAILURE, system_error, "malloc");
	//sorter->stack_b.hd = 0;
	//sorter->stack_b.size = 0;
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
	int	i;
	int	j;
	int issorted;
	t_number buffer;

	issorted = 1;
	j = 0;
	while(size - j >= 2)
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
				//check min to apply && check if this works????
				if (sorter->nb_qty > 20 && nbr < (sorter->nb_qty / 2) &&
					sorter->stack_b.arr[(sorter->stack_b.hd + 1) %
					sorter->stack_b.cap] > (sorter->nb_qty / 2))
					move(sorter, 1, rotate, stack_b);
			}
		}
	}
}

int	cheap_insert_from_b_into_lis(t_sorter *sorter)
{
	int		first_b;
	int		last_b;
	t_stack	stck_a;
	int		first_a;
	int		last_a;

	if (sorter->stack_b.size == 0)
		return (0);
	first_b = sorter->stack_b.arr[sorter->stack_b.hd];
	last_b = sorter->stack_b.arr[(sorter->stack_b.hd + sorter->stack_b.size -
	1) % sorter->stack_b.cap];
	stck_a = sorter->stack_a;
	first_a = stck_a.arr[stck_a.hd];
	last_a = stck_a.arr[(stck_a.hd + stck_a.size - 1) % stck_a.cap];
	if (sorter->numbers[first_a].lis && sorter->numbers[last_a].lis
		&& ((first_b < first_a && (first_b > last_a || last_a > first_a))
			|| (first_b > first_a && first_b > last_a && first_a < last_a)))
	{
		printf("%d\n", first_b);
		move(sorter, 1, push, stack_a);
		printf("Oops\n");
		return (1);
	}
	else if (sorter->numbers[first_a].lis && sorter->numbers[last_a].lis
		&& ((last_b < first_a && (last_b > last_a || last_a > first_a))
			|| (last_b > first_a && last_b > last_a && first_a < last_a)))
	{
		printf("%d\n", last_b);
		move(sorter, 1, revrotate, stack_b);
		move(sorter, 1, push, stack_a);
		printf("Oops_bis\n");
		return (1);
	}
	return (0);
}


/*void	fill_stack_b(t_sorter *sorter)
{
	int	first_lis;
	int	i;
	int	nbr;

	first_lis = -1;
	i = sorter->stack_a.hd;
	while (sorter->stack_a.arr[i] != first_lis)
	{
		nbr = sorter->stack_a.arr[i];
		if (sorter->numbers[nbr].lis == true)
		{
			if (first_lis == -1) 
				first_lis = nbr;
			move(sorter, 1, rotate, stack_a);
		}
		else
		{
			move(sorter, 1, push, stack_b);
			if (sorter->nb_qty > 100 && nbr > (sorter->nb_qty / 2))
				move(sorter, 1, rotate, stack_b);
		}
		i = sorter->stack_a.hd;
	}
}*/

