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

/*checker_bonus.h*/

#ifndef CHECKER_BONUS_H
# define CHECKER_BONUS_H

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

/*STRUCTS*/
typedef struct	s_stack
{
	int	*arr;
	int	hd;
	int	size;
	int cap;
}				t_stack;


typedef struct	s_checker
{
	t_stack		stack_a;
	t_stack		stack_b;
}				t_checker;
	
/*FUNCTIONS*/
/*parse_and_check_bonus.c*/
void	parse(t_checker *checker, int argc, char *argv[]);
int		atol_check_toi(char *str, t_checker *checker);
int		isduplicate(int *array, int current_index, int number);
void	check_moves(t_checker *checker);
int		is_sorted(t_stack stk);
/*operations_bonus.c*/
void	do_swap(t_checker *checker, t_stack_id stack_id);
void	do_push(t_checker *checker, t_stack_id stack_id);
void	do_rotate(t_checker *checker, t_stack_id stack_id);
void	do_revrotate(t_checker *checker, t_stack_id stack_id);
void	do_move(t_checker *checker, char *move);
/*cleanup_bonus.c*/
void	clean_exit(t_checker *checker, int exit_code, t_errtype errtype, char
*context);

#endif
