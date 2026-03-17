/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   operations.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cchaudeu <cchaudeu@student.42berlin.d      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/15 17:20:18 by cchaudeu          #+#    #+#             */
/*   Updated: 2026/03/17 15:39:46 by cchaudeu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

/*Swap the first 2 elements at the top of a stack.
 * Do nothing if there is only one element or none.*/

void	do_swap(t_sorter *sorter, t_stack_id stack_id)
{
	t_stack	*stack;
	int		temp;
	int		head;

	stack = NULL;
	if (stack_id == both_ab)
	{
		do_swap(sorter, stack_a);
		do_swap(sorter, stack_b);
	}
	else if (stack_id == stack_a && sorter->stack_a.size >= 2)
		stack = &sorter->stack_a;
	else if (stack_id == stack_b && sorter->stack_b.size >= 2)
		stack = &sorter->stack_b;
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

void	do_push(t_sorter *sorter, t_stack_id stack_id)
{
	t_stack *source;
	t_stack	*target;
	int		tar_new_head;

	if (stack_id == stack_a)
	{
		target = &sorter->stack_a;
		source = &sorter->stack_b;
	}
	else if (stack_id == stack_b)
	{
		target = &sorter->stack_b;
		source = &sorter->stack_a;
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

void	do_rotate(t_sorter *sorter, t_stack_id stack_id)
{
	t_stack	*stack;
	int		new_head;
	int		target_idx;

	if (stack_id == both_ab)
	{
		do_rotate(sorter, stack_a);
		do_rotate(sorter, stack_b);
	}
	else if (stack_id == stack_a)
		stack = &sorter->stack_a;
	else if (stack_id == stack_b)
		stack = &sorter->stack_b;
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

void	do_revrotate(t_sorter *sorter, t_stack_id stack_id)
{
	t_stack	*stack;
	int		new_head;
	int		source_idx;

	if (stack_id == both_ab)
	{
		do_revrotate(sorter, stack_a);
		do_revrotate(sorter, stack_b);
	}
	else if (stack_id == stack_a)
		stack = &sorter->stack_a;
	else if (stack_id == stack_b)
		stack = &sorter->stack_b;
	if (stack->size >= 2)
	{
		new_head = (stack->hd - 1 + stack->cap) % stack->cap;
		source_idx = (stack->hd + stack->size - 1) % stack->cap;
		stack->arr[new_head] = stack->arr[source_idx];
		stack->hd = new_head;
	}
}

void	move(t_sorter *sorter, int count, t_operation operation, t_stack_id stack)
{
	int	first_a;

	record_move(sorter, count, operation, stack);
	while (count--)
	{
		if (operation == swap)
			do_swap(sorter, stack);
		else if (operation == push)
		{
			do_push(sorter, stack);
			//maybe need to also change LIS status of first_a below
			if (stack == stack_a)
			{
				sorter->lis_len++;
				first_a = sorter->stack_a.arr[sorter->stack_a.hd];
				sorter->numbers[first_a].lis = true;
				if (first_a < sorter->stack_a.min)
					sorter->stack_a.min = first_a;
				else if (first_a > sorter->stack_a.max)
					sorter->stack_a.max = first_a;
			}
		}
		else if (operation == rotate)
			do_rotate(sorter, stack);
		else if (operation == revrotate)
			do_revrotate(sorter, stack);
	}
}
