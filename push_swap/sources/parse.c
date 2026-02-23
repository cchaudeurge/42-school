/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse_and_clean.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cchaudeu <cchaudeu@student.42berlin.d      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/17 15:54:37 by cchaudeu          #+#    #+#             */
/*   Updated: 2025/10/17 16:02:20 by cchaudeu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"


void	parse(t_sorter *sorter, int argc, char *argv[])
{
	int	number;
	int	i;

	sorter->nb_qty = argc - 1;
	sorter->numbers = (t_number *)ft_calloc((size_t)(argc - 1), sizeof(t_number));
	if (! sorter->numbers)
		clean_exit(sorter, EXIT_FAILURE, system_error, "malloc");
	i = 0;
	while (argv[i + 1])
	{
		number = atol_check_toi(argv[i + 1], sorter);
		if (isduplicate(sorter->numbers, i, number))
			clean_exit(sorter, EXIT_FAILURE, input_error, NULL);
		sorter->numbers[i].value = number;
		sorter->numbers[i].index = i;
		i++;
	}
}

int	atol_check_toi(char *str, t_sorter *sorter)
{
	long	nbr;
	int		sign;

	nbr = 0;
	sign = 1;
	while (*str == 32 || (*str >= 9 && *str <= 13))
		str++;
	if (*str == '+' || *str == '-')
	{
		if (*str == '-')
			sign = -sign;
		str++;
	}
	while (ft_isdigit(*str))
	{
		nbr = nbr * 10 + (*str - '0');
		if ((sign > 0 && nbr > 2147483647) || (sign < 0 && nbr > 2147483648))
			clean_exit(sorter, EXIT_FAILURE, input_error, NULL);
		str++;
	}
	if (*str)
		clean_exit(sorter, EXIT_FAILURE, input_error, NULL);
	return ((int)(sign * nbr));
}

int isduplicate(t_number *numbers, int current_index, int number)
{
	int	i;

	i = 0;
	while (i < current_index)
	{
		if (number == numbers[i].value)
			return (1);
		i++;
	}
	return (0);
}
/*Takes a pointer to a stack and populates that double-linked list with all the numbers
 * push-swap received, to do so, it checks that the input is correct (only valid
 * non repeaded integers). It returns -1 on error or the number of elements in
 * the list otherwise.*/

/*int	parse(t_stack **a, char *argv[])
{
	t_stack	*new_node;
	int		number;
	int		i;

	i = 0;
	while (argv[i])
	{
		number = atol_check_toi(argv[index], a);
		if (isduplicate(*a, number))
			clean_exit(*a, NULL, EXIT_FAILURE);
		new_node = (t_stack *)ft_calloc(sizeof(t_stack));
		if (!new_node)
			clean_exit(*a, NULL, EXIT_FAILURE);
		new_node->nbr = number;
		new_node->index = i;
		new_node->sorted = -1;
		stackadd_back(a, new_node); 
		i++;
	}
}

int	atol_check_toi(char *str, t_stack **a)
{
	long	nbr;
	int		sign;

	nbr = 0;
	sign = 1;
	while (*str == 32 || (*str >= 9 && *str <= 13))
		str++;
	if (*str == '+' || *str == '-')
	{
		if (*str == '-')
			sign = -sign;
		str++;
	}
	while (ft_isdigit(*str))
	{
		nbr = nbr * 10 + (*str - '0');
		if ((sign > 0 && nbr > 2147483647) || (sign < 0 && nbr > 2147483648))
			clean_exit(*a, NULL, EXIT_FAILURE);
		str++;
	}
	if (*str)
		clean_exit(*a, NULL, EXIT_FAILURE);
	return ((int)(sign * nbr));
}

int isduplicate(t_stack	*a, int number)
{
	while (a && a->next)
	{
		if (number == a->nbr)
			return (1);
		a = a->next;
	}
	return (0);
}

void	clean_exit(t_stack *a, t_stack *b, int status)
{
	free_stack(&a);
	free_stack(&b);
	if (status == EXIT_FAILURE)
		ft_printf("Error\n");
	exit(status);
}

void	free_stack(t_stack **stack)
{
	t_stack	*next_node;

	while (*stack)
	{
		next_node = (*stack)->next;
		free(*stack);
		*stack = next_node;
	}
}*/
