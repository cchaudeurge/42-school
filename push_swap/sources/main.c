/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cchaudeu <cchaudeu@student.42berlin.d      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/10 19:38:15 by cchaudeu          #+#    #+#             */
/*   Updated: 2025/10/17 15:53:59 by cchaudeu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	main(int argc, char *argv[])
{
	if (argc < 2)
		clean_exit(NULL, EXIT_FAILURE, input_error, NULL);	
	push_swap(argc, argv);
	return (0);
//	print_numbers(sorter.numbers, sorter.nb_qty);
//	create_move_lst(&sorter);
//	printf("LIS is %d/%d\n", sorter.lis_len, sorter.nb_qty);
//	print_lis(&sorter);
//	printf("Lis_min = %d, lis_max = %d\n", sorter.stack_a.min, sorter.stack_a.max);
//	print_numbers(sorter.numbers, sorter.nb_qty);
//	print_stack(sorter, sorter.stack_a, 'a');
//	print_stack(sorter, sorter.stack_b, 'b');
//	move(&sorter, 1, swap, stack_a);
//	print_stack(sorter, sorter.stack_a, 'a');
//	printf("lis_len after b filled = %d\n", sorter.lis_len);
//	print_lis(&sorter);
//	printf("Lis_min = %d, lis_max = %d\n", sorter.stack_a.min, sorter.stack_a.max);
//	print_stack(sorter, sorter.stack_b, 'b');
//	printf("b was filled\n");
//	find_cheapest(&sorter);
//	optimize_rotations(&sorter.cheapest_to_a);
//	printf("Cheapest: ar = %d, br = %d, c2a = %d\n", sorter.cheapest_to_a.a_rot,
//	sorter.cheapest_to_a.b_rot, sorter.cheapest_to_a.c2a);
//	move_cheapest(&sorter);
//	printf("cheapest was moved\n");
//	print_stack(sorter, sorter.stack_a, 'a');
//	printf("lis_len = %d\n", sorter.lis_len);
//	print_lis(&sorter);
//	printf("Lis_min = %d, lis_max = %d\n", sorter.stack_a.min, sorter.stack_a.max);
//	print_stack(sorter, sorter.stack_b, 'b');
//	printf("Cheapest: ar = %d, br = %d, c2a = %d\n", sorter.cheapest_to_a.a_rot,
//	sorter.cheapest_to_a.b_rot, sorter.cheapest_to_a.c2a);
//	print_move_count(sorter);
//	printf("LIS is %d/%d\n", sorter.lis_len, sorter.nb_qty);
//	print_move_count(sorter);
}

void	push_swap(int argc, char *argv[])
{
	t_sorter	sorter;
	
	ft_bzero(&sorter, sizeof(t_sorter));
	parse(&sorter, argc, argv);
	create_and_fill_stacks(&sorter);
	flag_longest_lis(&sorter);
	fill_stack_b(&sorter);
	empty_b(&sorter);
	min_a_to_top(&sorter);
	optimize_s_s(sorter.move_lst);
	optimize_r_rr(sorter.move_lst);
	optimize_pa_pb(sorter.move_lst);
	optimize_ra_pa_rra(&sorter, sorter.move_lst);
	put_move_lst(sorter.move_lst);
	clean_exit(&sorter, -1, no_error, NULL);
}

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

	printf("Stack %c head is %d, size is %d, and capacity is %d\n", a_or_b, stack.hd,
	stack.size, stack.cap);
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
}

/*int	main(int argc, char *argv[])
{
	t_stack	*a;

	a = NULL;
}

void	push_swap(t_stack **a, char	*argv[])
{
	if (!parse)
}*/
		
/*int	is_short_number(char *str)
{
	int	i;
	int digits;

	i = 0;
	length = 0;
	if (str[i] == '-' || str[i] == '+')
		i++;
	while (str[i] && str[i] == '0')
		i++;
	while (str[i] && ft_isdigit(str[i]))
	{
		i++;
		digits++;
	}
	if (str[i] || digits > 10)
		return (0);
	return (1);
}*/
/*void	*stacknew(int number, int i, t_stack **a)
{
	t_stack	*new_node;
	t_stack	*last;

	new_node = (t_stack *)malloc(sizeof(t_stack));
	if (!new_node)
		clean_exit(*a, NULL, EXIT_FAILURE);
	new_node->nbr = number;
	new_node->index = i;
	new_node->sorted = -1;
	new_node->prev = NULL;
	new_node->next = NULL;
	return (new_node);
}*/

