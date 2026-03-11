
#include "push_swap.h"


void	parse(t_checker *checker, int argc, char *argv[])
{
	int	number;
	int	i;
	int	stack_capacity;

	stack_capacity = argc - 1;
	checker->stack_a.arr = (int *)malloc(stack_capacity * sizeof(int));
	checker->stack_b.arr = (int *)malloc(stack_capacity * sizeof(int));
	if (!checker->stack_a.arr || !checker->stack_b.arr)
		clean_exit(checker, EXIT_FAILURE, system_error, "malloc");
	//checker->stack_b.hd = 0;
	//checker->stack_b.size = 0;
	checker->stack_b.cap = stack_capacity;
	i = 0;
	while (argv[i + 1])
	{
		number = atol_check_toi(argv[i + 1], checker);
		if (isduplicate(checker->stack_a.arr, i, number))
			clean_exit(checker, EXIT_FAILURE, input_error, NULL);
		checker->stack_a.arr[i] = number;
		i++;
	}
	checker->stack_a.hd = 0;
	checker->stack_a.size = i;
	checker->stack_a.cap = stack_capacity;
}

int	atol_check_toi(char *str, t_checker *checker)
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
			clean_exit(checker, EXIT_FAILURE, input_error, NULL);
		str++;
	}
	if (*str)
		clean_exit(checker, EXIT_FAILURE, input_error, NULL);
	return ((int)(sign * nbr));
}

int isduplicate(int *array, int current_index, int number)
{
	int	i;

	i = 0;
	while (i < current_index)
	{
		if (number == array[i])
			return (1);
		i++;
	}
	return (0);
}

void	check_moves(t_checker *checker)
{
	char	*move;

	move = ft_gnl_with_nl(0);
	while (move)
	{
		do_move(checker, move);
		free(move);
		move = ft_gnl_with_nl(0);
	}
	if (is_sorted(checker->stack_a) && checker->stack_b.size == 0)
		ft_putendl_fd("OK", 1);
	else
		ft_putendl_fd("KO", 1);
}

		new_node = ft_lstnew(line);
		if (!new_node)
		{
			free(line);
			ft_lstclear(&line_lst, free);
			close(fd);
			clean_exit(game, EXIT_FAILURE, sys_err, "malloc");
		}
		ft_lstadd_back(&line_lst, new_node);
		line = gnl_without_nl(fd);
	}
	return (line_lst);
}

int	is_sorted(t_stack stk)
{
	int	i;
	int	*arr;
	int	hd;
	int	size;
	int	cap;

	i = 0;
	while (i + 1 < stk.size)
	{
		if (stk.arr[(stk.hd + i) % stk] > stk.arr[(stk.hd + i + 1) % stk])
			return (0);
		i++;
	}
	return (1);
}
