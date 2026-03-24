/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cchaudeu <cchaudeu@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/10 19:38:15 by cchaudeu          #+#    #+#             */
/*   Updated: 2026/03/18 20:15:09 by cchaudeu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	main(int argc, char *argv[])
{
	if (argc < 2)
		clean_exit(NULL, EXIT_FAILURE, input_error, NULL);
	push_swap(argc, argv);
	return (0);
}

/*Testing functions for evaluation

void	print_lis(t_sorter *sorter)
{
	int	i;

	i = 0;
	while (i < sorter->nb_qty)
	{
		if (sorter->numbers[i].lis == true)
			printf("%d\n", sorter->numbers[i].value);
		i++;
	}
}
void	print_numbers(t_number *numbers, int size)
{
	int	i;

	i = 0;
	while (i < size)
	{
		printf("Index %d: value is %d, index is %d\n", i, numbers[i].value,
		numbers[i].index);
		i++;
	}
}

void	print_stack(t_sorter sorter, t_stack stack, char a_or_b)
{
	int	i;
	int index;

	printf("Stack %c head is %d, size is %d, and capacity is %d\n",
        a_or_b, stack.hd, stack.size, stack.cap);
	i = 0;
	index = stack.hd;
	while (i < stack.size)
	{
		printf("Index %d: normalized value is %d, initial value was %d\n", i,
		stack.arr[index], sorter.numbers[stack.arr[index]].value);
		index = (index + 1) % stack.cap;
		i++;
	}
}

void	print_move_count(t_sorter sorter)
{
	t_list	*move_list;
	int move_count;

	move_count = 0;
	move_list = sorter.move_lst;
	while (move_list)
	{
		move_count += ((t_move *)move_list->content)->count;
		move_list = move_list->next;
	}
	printf("Moves: %d\n", move_count);
}*/