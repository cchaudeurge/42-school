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
	t_sorter	sorter;

	ft_bzero(&sorter, sizeof(t_sorter));
	if (argc < 2)
		clean_exit(&sorter, EXIT_FAILURE, input_error, NULL);
	parse(&sorter, argc, argv);
	printf("got here");
	print_numbers(sorter.numbers, sorter.nb_qty);
	create_and_fill_stacks(&sorter);
	print_numbers(sorter.numbers, sorter.nb_qty);
	print_stack(sorter.stack_a, 'a');
	print_stack(sorter.stack_b, 'b');
	clean_exit(&sorter, EXIT_SUCCESS, 0, NULL);
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

void	print_stack(t_stack stack, char a_or_b)
{
	int	i;
	int index;

	printf("Stack %c head is %d, size is %d, and capacity is %d\n", a_or_b, stack.head,
	stack.size, stack.capacity);
	i = 0;
	index = stack.head;
	while (i < stack.size)
	{
		printf("Index %d: normalized value is %d\n", i, stack.array[index]);
		index = (index + 1) % stack.capacity;
		i++;
	}
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

