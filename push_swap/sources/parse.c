/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cchaudeu <cchaudeu@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/17 15:54:37 by cchaudeu          #+#    #+#             */
/*   Updated: 2026/03/18 14:13:19 by cchaudeu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	parse(t_sorter *sorter, int argc, char *argv[])
{
	int	number;
	int	i;

	sorter->nb_qty = argc - 1;
	sorter->numbers
		= (t_number *)ft_calloc((size_t)(argc - 1), sizeof(t_number));
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

int	isduplicate(t_number *numbers, int current_index, int number)
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
