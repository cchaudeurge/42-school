/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   operations1.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cchaudeu <cchaudeu@student.42berlin.d      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/15 17:20:18 by cchaudeu          #+#    #+#             */
/*   Updated: 2025/10/17 16:06:31 by cchaudeu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

/*Swap the first 2 elements at the top of a stack.
 * Do nothing if there is only one element or none.*/

void	do_swap(t_checker *checker, t_stack_id stack_id)
{
	t_stack	*stack;
	int		temp;
	int		head;

	stack = NULL;
	if (stack_id == both_ab)
	{
		do_swap(checker, stack_a);
		do_swap(checker, stack_b);
	}
	else if (stack_id == stack_a && checker->stack_a.size >= 2)
		stack = &checker->stack_a;
	else if (stack_id == stack_b && checker->stack_b.size >= 2)
		stack = &checker->stack_b;
	if (stack)
	{
		head = stack->hd;
		temp = stack->arr[head];
		stack->arr[head] = stack->arr[(head + 1) % stack->cap];
		stack->arr[(head + 1) % stack->cap] = temp;
	}
}

/*Take the first element at the top of a stack and put it at the top of the
 * other stack. Do nothing if the first stack is empty. pa (push a) pushes the
 * first element at the top of b to a (push to a).*/

void	do_push(t_checker *checker, t_stack_id stack_id)
{
	t_stack *source;
	t_stack	*target;
	int		tar_new_head;

	if (stack_id == stack_a)
	{
		target = &checker->stack_a;
		source = &checker->stack_b;
	}
	else if (stack_id == stack_b)
	{
		target = &checker->stack_b;
		source = &checker->stack_a;
	}
	if (source->size >= 1)
	{
		tar_new_head = (target->hd - 1 + target->cap) % target->cap;
		target->arr[tar_new_head] = source->arr[source->hd];
		target->hd = tar_new_head;
		target->size++;
		source->hd = (source->hd + 1) % source->cap;
		source->size--;
	}
}

/*Shift up all elements of a stack by 1.
 * The first element becomes the last one.*/

void	do_rotate(t_checker *checker, t_stack_id stack_id)
{
	t_stack	*stack;
	int		new_head;
	int		target_idx;

	if (stack_id == both_ab)
	{
		do_rotate(checker, stack_a);
		do_rotate(checker, stack_b);
	}
	else if (stack_id == stack_a)
		stack = &checker->stack_a;
	else if (stack_id == stack_b)
		stack = &checker->stack_b;
	if (stack->size >= 2)
	{
		new_head = (stack->hd + 1) % stack->cap;
		target_idx = (stack->hd + stack->size) % stack->cap;
		stack->arr[target_idx] = stack->arr[stack->hd];
		stack->hd = new_head;
	}
}

/*Shift down all elements of a stack by 1.
 * The last element becomes the first one.*/

void	do_revrotate(t_checker *checker, t_stack_id stack_id)
{
	t_stack	*stack;
	int		new_head;
	int		source_idx;

	if (stack_id == both_ab)
	{
		do_revrotate(checker, stack_a);
		do_revrotate(checker, stack_b);
	}
	else if (stack_id == stack_a)
		stack = &checker->stack_a;
	else if (stack_id == stack_b)
		stack = &checker->stack_b;
	if (stack->size >= 2)
	{
		new_head = (stack->hd - 1 + stack->cap) % stack->cap;
		source_idx = (stack->hd + stack->size - 1) % stack->cap;
		stack->arr[new_head] = stack->arr[source_idx];
		stack->hd = new_head;
	}
}

void	do_move(t_checker *checker, char *move)
{
	if (ft_strncmp(move, "pa\n", 3) == 0)
		do_push(checker, stack_a);
	else if (ft_strncmp(move, "pb\n", 3) == 0)
		do_push(checker, stack_b);
	else if (ft_strncmp(move, "ra\n", 3) == 0)
		do_rotate(checker, stack_a);
	else if (ft_strncmp(move, "rb\n", 3) == 0)
		do_rotate(checker, stack_b);
	else if (ft_strncmp(move, "rr\n", 3) == 0)
		do_rotate(checker, both_ab);
	else if (ft_strncmp(move, "rra\n", 3) == 0)
		do_revrotate(checker, stack_a);
	else if (ft_strncmp(move, "rrb\n", 3) == 0)
		do_revrotate(checker, stack_b);
	else if (ft_strncmp(move, "rrr\n", 3) == 0)
		do_revrotate(checker, both_ab);
	else if (ft_strncmp(move, "sa", 3) == 0)
		do_swap(checker, stack_a);
	else if (ft_strncmp(move, "sb", 3) == 0)
		do_swap(checker, stack_b);
	else if (ft_strncmp(move, "sss", 3) == 0)
		do_swap(checker, both_ab);
	else
		clean_exit(checker, EXIT_FAILURE, input_error, NULL);
}
