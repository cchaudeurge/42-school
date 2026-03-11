
#include "push_swap.h"

int	main(int argc, char *argv[])
{
	t_checker	checker;

	if (argc < 2)
		clean_exit(NULL, EXIT_FAILURE, input_error, NULL);
	parse(&checker, argc, argv);
	check_moves(&checker);
}
