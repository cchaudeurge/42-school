#include "push_swap.h"

void	clean_exit(t_sorter *sorter, int exit_code, t_errtype errtype, char	*context)
{
	if (sorter)
	{
		if (sorter->numbers)
			free(sorter->numbers);
		if (sorter->stack_a.array)
			free(sorter->stack_a.array);
		if (sorter->stack_b.array)
			free(sorter->stack_b.array);
	}
	if (exit_code == EXIT_FAILURE)
	{
		ft_putendl_fd("Error", 2);
		if (errtype == system_error)
			perror(context);
	}
	exit(exit_code);
}
