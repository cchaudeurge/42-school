
#include "push_swap_bonus.h"

int	main(int argc, char *argv[])
{
	t_checker	checker;

	if (argc < 2)
		clean_exit(NULL, EXIT_FAILURE, input_error, NULL);
	parse(&checker, argc, argv);
	check_moves(&checker);
	clean_exit(&checker, -1, no_error, NULL);
	return (0);
}
