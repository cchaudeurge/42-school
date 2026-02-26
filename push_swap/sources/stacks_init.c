#include "push_swap.h"

void	create_and_fill_stacks(t_sorter *sorter)
{
	int		issorted;
	size_t	stack_size;
	int		i;
	int		idx;

	issorted = bubble_sort(sorter->numbers, sorter->nb_qty);
	if (issorted)
	{
		//remove printf
		printf("is sorted");
		clean_exit(sorter, EXIT_SUCCESS, no_error, NULL);
	}
	stack_size = (size_t)sorter->nb_qty;
	sorter->stack_a.array = (int *)malloc(stack_size * sizeof(int));
	sorter->stack_b.array = (int *)malloc(stack_size * sizeof(int));
	if (!sorter->stack_a.array || !sorter->stack_b.array)
		clean_exit(sorter, EXIT_FAILURE, system_error, "malloc");
	//sorter->stack_b.head = 0;
	//sorter->stack_b.size = 0;
	sorter->stack_b.capacity = sorter->nb_qty;
	i = 0;
	while (i < sorter->nb_qty)
	{
		idx = sorter->numbers[i].index;
		sorter->stack_a.array[idx] = i;
		i++;
	}
	sorter->stack_a.head = 0;
	sorter->stack_a.size = i;
	sorter->stack_a.capacity = i;
}

/*Sorts the initial array so the values can be normalized by their sorted index.
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

/*void	fill_stack_b(t_sorter *sorter)
{
	int	first_lis;
	int	i;

	first_lis = -1;
	i = sorter->stack_a.head;
	while (sorter->stack_a.array[i] != first_lis)
	{
		if

	*/

