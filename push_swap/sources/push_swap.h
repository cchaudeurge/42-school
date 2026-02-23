/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cchaudeu <cchaudeu@student.42berlin.d      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/10 21:15:35 by cchaudeu          #+#    #+#             */
/*   Updated: 2025/10/17 16:13:19 by cchaudeu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

/*push_swap.h*/

#ifndef PUSH_SWAP_H
# define PUSH_SWAP_H

/*For exit, malloc, free*/
# include <stdlib.h>
/*For read, write*/
# include <unistd.h>
/*For perror*/
# include <stdio.h>
# include <errno.h>
/*For strerror , size_t*/
# include <string.h>
/*Libft*/
# include "../libft/libft.h"

/*STRUCTS*/

typedef struct	s_number
{
	int		value;
	int 	index;
	bool	lis;
	//int	r_cost_to_top;
	//int	rr_cost_to_top;
	//int	cost_to_a;
	int		target;
	struct 	s_number	*target_ptr;
}				t_number;

typedef struct	s_stack
{
	int	*array;
	int	head;
	int	size;
	int capacity;
}				t_stack;

typedef struct	s_moves
{
	int	ra;
	int rb;
	int	rr;
	int rra;
	int rrb;
	int	rrr;
	int sa;
	int sb;
	int	ss;
	int pa;
	int	pb;
}				t_moves;

typedef struct	s_lis
{
	int	nbr;
	int	lis;
	int	prev_idx;
}				t_lis;

typedef struct	s_sorter
{
	t_number	*numbers;
	int			nb_qty;
	t_stack		stack_a;
	t_stack		stack_b;
	int			lis_len;
	int			lis_head;
	int			cheapest_to_a;
	int			cost_to_a;
	t_moves		moves_to_a;
}				t_sorter;
	
typedef enum	e_errtype
{
	system_error,
	input_error,
	no_error
}				t_errtype;

/*FUNCTIONS*/
/*main.c testing XXXXXXXXXXXXXXXXXXXXXXXXX*/
void	print_numbers(t_number *numbers, int size);
void	print_stack(t_stack stack, char a_or_b);
/*parse.c*/
void	parse(t_sorter *sorter, int argc, char *argv[]);
int	atol_check_toi(char *str, t_sorter *sorter);
int isduplicate(t_number *numbers, int current_index, int number);
/*stacks_init.c*/
void	create_and_fill_stacks(t_sorter *sorter);
int	bubble_sort(t_number *numbers, int size);
/*lis.c*/
void	flag_longest_lis(t_sorter *sorter);
int	fill_lis_array(t_lis *array, t_sorter *sorter);
void	find_longest_lis(t_sorter *sorter);
int	lis_length(t_stack stack, int head);
int	upper_bound_sorted(int *array, int nbr, int max_index);
/*cleanup.c*/
void	clean_exit(t_sorter *sorter, int exit_code, t_errtype errtype, char
*context);

#endif
