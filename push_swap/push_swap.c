/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cchaudeu <cchaudeu@student.42berlin.d      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/10 19:38:15 by cchaudeu          #+#    #+#             */
/*   Updated: 2025/10/11 04:26:34 by cchaudeu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

/*Program needs to:
 * 	- Read numbers from the sdtint into list A.
 * 		For each arg:
 * 		- Check that string represents a valid integer (minus sign [optional], followed only by
 * 		digits)
 * 		- atoi(argv[i]) into a node
 * 		-*/

int	main(int argc, char *argv[])
{
	t_stack	*a;

	a = NULL;
}

void	push_swap(t_stack **a, char	*argv[])
{
	if (!parse)
}

/*Takes a pointer to a stack and populates that double-linked list with all the numbers
 * push-swap received, to do so, it checks that the input is correct (only valid
 * non repeaded integers). It returns -1 on error or the number of elements in
 * the list otherwise.*/

int	parse(t_stack **a, char *argv[])
{
	t_stack	*new_node;
	int		number;
	char	*nbstr;

	while (*argv)
	{
		number = atoltoi(*argv);
		if (isduplicate(*a, number))
			clean_exit(*a, NULL, EXIT_FAILURE);
		new_node = 

		XXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXX
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

t_stack	*stacknew(int number)
{
	t_stack	*new_node;

	new_node = (t_stack *)malloc(sizeof(t_stack));
XXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXX
	new_node->nbr = number;
	new_node->indx = -1;
	new_node->prev = NULL;
	new_node->next = NULL;
	return (new_node);
}

void	clean_exit(t_stack *a, t_stack *b, int status)
{
	free_stack(a);
	free_stack(b);
	if (status == EXIT_FAILURE)
		ft_printf("Error\n");
	exit(status);
}

void	free_stack(t_stack *stack)
{
	t_stack	*next_node;

	while (stack)
	{
		next_node = stack->next;
		free(stack);
		stack = next_node;
	}
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
