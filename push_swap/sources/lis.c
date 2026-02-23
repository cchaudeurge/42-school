void	flag_longest_lis(t_sorter *sorter)
{
	t_lis	lis_array[sorter->nb_qty];
	int		last_elem_index;
	int	i;
	int	nbr;

	find_longest_lis(sorter);
	last_elem_index = fill_lis_array(lis_array, sorter);
	i = last_elem_index;
	while (i != array[i].prev_idx)
	{
		nbr = array[i].nbr;
		sorter->numbers[nbr].lis = true;
		i = array[i].prev_idx;
	}
	nbr = array[i].nbr;
	sorter->numbers[nbr].lis = true;
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
	int j;

	i = 0;
	while (i < sorter->nb_qty)
	{
		array[i].nbr = sorter->stack_a.array[(sorter->lis_head + i) % sorter->nb_qty];
		lis_array[i].lis = 1;
		lis_array[i].prev_idx = i;
		j = 0
		while (j < i)
		{
			if (array[j].nbr < array[i].nbr && array[j].lis + 1 > array[i].lis)
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
	int current_lis_len;
	
	sorter->lis_len = lis_length(sorter->stack_a, 0);
	sorter->lis_head = 0;
	current_head = 1;
	while (current_head < sorter->stack_a.capacity)
	{
		current_lis_len = lis_length(sorter->stack.a, current_head);
		if (current_lis_len > sorter->lis_len)
		{
			sorter->lis_len = current_lis_len;
			sorter->lis_head = current_head;
		}
		if (current_lis_len == sorter->stack_a.capacity)
			return ; 
		current_head++;
	}
}

int	lis_length(t_stack stack, int head)
{
	int	lis_array[stack->size];
	int last;
	int	i;
	int insertion_idx;

	lis_array[head] = stack.array[0];
	last = 0;
	i = (head + 1) % stack.capacity;
	while (i != head)
	{
		if (stack.array[i] > lis_array[last])
		{
			last++;
			lis_array[last] = stack.array[i];
		}
		else
		{
			insertion_idx = upper_bound_sorted(lis_array, stack.array[i], last); 
			lis_array[insertion_index] = stack.array[i];
		}
		i = (i + 1) % stack.capacity;
	}
	return (last + 1);
}

int	upper_bound_sorted(int *array, int nbr, int max_index)
{
	int	low;
	int	high;
	int mid;
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
