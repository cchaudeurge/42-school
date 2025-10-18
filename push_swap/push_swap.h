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

/*Double-linked list*/
typedef struct s_stack
{
	int				nbr;
	int				index;
	int				sorted;
	struct s_stack	*prev;
	struct s_stack	*next;
}					t_stack;

/*Stack group*/
typedef struct s_sgroup
{
	t_stack	*a;
	t_stack	*b;
}			t_sgroup

/*Operations*/
/*operations.c*/
void	swap(t_sgroup *group, char identifier);
void	push(t_sgroup *group, char identifier);
void	rotate(t_sgroup *group, char identifier);
void	revrotate(t_group *group, char identifier);

/*List manipulation*/
/*lists.c*/
t_stack	*getlast(t_stack *stack);
void	stackadd_front(t_stack **stack, t_stack *new);
void	stackadd_back(t_stack **stack, t_stack *new);

/*Input parsing and clean exit*/
/*parse_and_clean.c*/
int		parse(t_stack **a, char *argv[]);
int		atol_check_toi(char *str, t_stack **a);
int 	isduplicate(t_stack	*a, int number);
void	clean_exit(t_stack *a, t_stack *b, int status);

#endif
