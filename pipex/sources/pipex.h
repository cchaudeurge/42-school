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

/*pipex.h*/

#ifndef PIPEX_H
# define PIPEX_H

/*For exit, malloc, free*/
# include <stdlib.h>
/*For read, write*/
# include <unistd.h>
/*For perror*/
# include <stdio.h>
# include <errno.h>
/*For strerror , size_t*/
# include <string.h>
///*For boolean*/
//# include <stdbool.h>
/*Libft*/
# include "../libft/libft.h"

typedef struct s_piper
{
	
typedef enum	e_errtype
{
	system_error,
	input_error,
	no_error
}				t_errtype;

typedef enum	e_stack_id
{
	stack_a,
	stack_b,
	both_ab
}				t_stack_id;

typedef enum	e_operation
{
	swap,
	push,
	rotate,
	revrotate
}				t_operation;

/*STRUCTS*/
typedef struct	s_move
{
	int			count;
	t_operation	operation;
	t_stack_id  stack;
}		t_move;

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

/*For stack_a, the pivot is the smallest of the sorted sequence, for stack_b,
 * the pivot is sorter->nub_qty / 2*/
typedef struct	s_stack
{
	int	*arr;
	int	hd;
	int	size;
	int cap;
	int	min;
	int	max;
}				t_stack;


typedef struct s_lis
{
	int	nbr;
	int	lis;
	int	prev_idx;
}				t_lis;

typedef struct s_cost
{
	int	b_rot;
	int	a_rot;
	int r_rot;
	int	c2a;
}			t_cost;			

typedef struct	s_sorter
{
	t_number	*numbers;
	int			nb_qty;
	t_stack		stack_a;
	t_stack		stack_b;
	int			lis_len;
	int			lis_head;
	t_cost		cheapest_to_a;
//	int			cost_to_a;
//	t_moves		*moves_to_a;
	t_list		*move_lst;
}				t_sorter;
	
/*FUNCTIONS*/
/*main.c testing XXXXXXXXXXXXXXXXXXXXXXXXX*/
void	push_swap(int argc, char *argv[]);
void	print_numbers(t_number *numbers, int size);
void	print_stack(t_sorter sorter, t_stack stack, char a_or_b);
void	print_lis(t_sorter *sorter);
void	print_move_count(t_sorter sorter);
/*parse.c*/
void	parse(t_sorter *sorter, int argc, char *argv[]);
int	atol_check_toi(char *str, t_sorter *sorter);
int isduplicate(t_number *numbers, int current_index, int number);
/*stacks_init.c*/
void	create_move_lst(t_sorter *sorter);
void	create_and_fill_stacks(t_sorter *sorter);
int	bubble_sort(t_number *numbers, int size);
void	fill_stack_b(t_sorter *sorter);
int	cheap_insert_from_b_into_lis(t_sorter *sorter);
/*lis.c*/
void	flag_longest_lis(t_sorter *sorter);
int	fill_lis_array(t_lis *array, t_sorter *sorter);
void	find_longest_lis(t_sorter *sorter);
int	lis_length(t_stack stack, int head);
int	upper_bound_sorted(int *array, int nbr, int max_index);
/*operations.c*/
void	do_swap(t_sorter *sorter, t_stack_id stack_id);
void	do_push(t_sorter *sorter, t_stack_id stack_id);
void	do_rotate(t_sorter *sorter, t_stack_id stack_id);
void	do_revrotate(t_sorter *sorter, t_stack_id stack_id);
void	move(t_sorter *sorter, int count, t_operation operation, t_stack_id stack);
/*target.c*/
int	find_target_idx(int nbr, t_stack *stack);
int find_smallest_bigger(int x, t_stack s, int lo, int hi);
int	find_x_idx(int x, t_stack s, int lo, int hi);
/*cost.c*/
void	find_cheapest(t_sorter *sorter);
void	calculate_cost(int b_idx, t_cost *cost, t_sorter *sorter);
int	alternate_c2t(int c2t, t_stack stack);
int	cheapest_c2t(int idx, t_stack stack);
/*empty_b.c*/
void	min_a_to_top(t_sorter *sorter);
void	empty_b(t_sorter *sorter);
void	move_cheapest(t_sorter *sorter);
void	optimize_rotations(t_cost *cost);
/*optimizations.c*/
void	optimize_lis(t_sorter *sorter);
void	optimize_s_s(t_list *move_lst);
void	optimize_r_rr(t_list *move_lst);
void	optimize_pa_pb(t_list *move_lst);
void	optimize_ra_pa_rra(t_sorter *sorter, t_list *move_lst);
/*move_list.c*/
void	record_move(t_sorter *sorter, int count, t_operation operation,
t_stack_id stack);
t_list	*create_move_node(t_sorter *sorter, int count, t_operation operation,
t_stack_id stack);
void	put_move_lst(t_list *move_lst);
void	put_move(t_move move);
/*cleanup.c*/
void	clean_exit(t_sorter *sorter, int exit_code, t_errtype errtype, char
*context);

#endif
