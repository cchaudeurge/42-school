/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   move_list.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cchaudeu <cchaudeu@student.42berlin.d      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/03/17 15:39:18 by cchaudeu          #+#    #+#             */
/*   Updated: 2026/03/17 15:39:23 by cchaudeu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	record_move(t_sorter *sorter, int count, t_operation operation, t_stack_id stack)
{
	t_list	*prev_move_node;
	t_list	*new_node;

	prev_move_node = ft_lstlast(sorter->move_lst);
	if (prev_move_node && prev_move_node->content
		&& ((t_move *)prev_move_node->content)->operation == operation
		&& ((t_move *)prev_move_node->content)->stack == stack)
		((t_move *)prev_move_node->content)->count += count;
	else
	{
		new_node = create_move_node(sorter, count, operation, stack);
		ft_lstadd_back(&(sorter->move_lst), new_node);
	}
}

t_list	*create_move_node(t_sorter *sorter, int count, t_operation operation,
t_stack_id stack)
{
	t_move	*move;
	t_list	*new_node;

	move = (t_move *)malloc(sizeof(t_move));
	if (!move)
		clean_exit(sorter, EXIT_FAILURE, system_error, "malloc");
	move->count = count;
	move->operation = operation;
	move->stack = stack;
	new_node = ft_lstnew(move);
	if (!new_node)
	{
		free(move);
		clean_exit(sorter, EXIT_FAILURE, system_error, "malloc");
	}
	return (new_node);
}

void	put_move_lst(t_list *move_lst)
{
	int		i;
	t_move	move;

	while (move_lst && move_lst->content)
	{
		move = *(t_move *)move_lst->content;
		i = move.count;
		while (i--)
			put_move(move);
		move_lst = move_lst->next;
	}
}


void	put_move(t_move move)
{
	if (move.operation == swap)
		write(1, "s", 1);
	else if (move.operation == push)
		write(1, "p", 1);
	else if (move.operation == rotate)
		write(1, "r", 1);
	else if (move.operation == revrotate)
		write(1, "rr", 2);
	if (move.stack == stack_a)
		write(1, "a", 1);
	else if (move.stack == stack_b)
		write(1, "b", 1);
	else if (move.stack == both_ab && move.operation == swap)
		write(1, "s", 1);
	else if (move.stack == both_ab)
		write(1, "r", 1);
	write(1, "\n", 1);
}



