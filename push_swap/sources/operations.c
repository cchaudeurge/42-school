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

void	swap(t_sorter *sorter, t_stack_id stack_id)
{
	t_stack	*stack;
	int		temp;
	int		head;

	stack = NULL;
	if (stack == both_ab)
	{
		swap(sorter, stack_a);
		swap(sorter, stack_b);
	}
	else if (stack == stack_a && sorter->stack_a.size >= 2)
		stack = &sorter->stack_a;
	else if (stack == stack_b && sorter->stack_b.size >= 2)
		stack = &sorter->stack_b;
	if (stack)
	{
		head = stack->head;
		tem = stack->array[head];
		stack->array[head] = stack->array[(head + 1) % stack->capacity];
		stack->array[(head + 1) % stack->capacity] = temp;
	}
}

/*Take the first element at the top of a stack and put it at the top of the
 * other stack. Do nothing if the first stack is empty. pa (push a) pushes the
 * first element at the top of b to a (push to a).*/

void	push(t_sorter *sorter, t_stack_id stack_id)
{
	t_stack *source;
	t_stack	*target;
	int		tar_new_head;

	if (stack_id == stack_a)
	{
		target = &sorter->stack_a;
		source = &sorter->stabc_b;
	}
	else if (stack_id == stack_b)
	{
		target = &sorter->stack_b;
		source = &sorter->stack_a;
	}
	if (source->size >= 1)
	{
		tar_new_head = (target->head - 1 + target->capacity) % target->capacity;
		target->array[tar_new_head] = source->array[source->head];
		target->head = tar_new_head;
		target->size++;
		source->head = (source->head + 1) % source->capacity;
		source->size--;
	}
}

/*Shift up all elements of a stack by 1.
 * The first element becomes the last one.*/

void	rotate(t_sorter *sorter, t_stack_id stack_id)
{
	t_stack	*stack;
	int		new_head;
	int		target_idx;

	if (stack_id == both_ab)
	{
		rotate(sorter, stack_a);
		rotate(sorter, stack_b);
	}
	else if (stack_id == stack_a)
		stack = &sorter->stack_a;
	else if (stack_id == stack_b)
		stack = &sorter->stack_b;
	if (stack->size >= 2)
	{
		new_head = (stack->head + 1) % stack->capacity;
		target_idx = (stack->head + size) % stack->capacity;
		stack->array[target_idx] = stack->array[stack->head];
		stack->head = new_head;
	}
}

/*Shift down all elements of a stack by 1.
 * The last element becomes the first one.*/

void	revrotate(t_sorter *sorter, t_stack_id stack_id)
{
	t_stack	*stack;
	int		new_head;
	int		source_idx;

	if (stack_id == both_ab)
	{
		rotate(sorter, stack_a);
		rotate(sorter, stack_b);
	}
	else if (stack_id == stack_a)
		stack = &sorter->stack_a;
	else if (stack_id == stack_b)
		stack = &sorter->stack_b;
	if (stack->size >= 2)
	{
		new_head = (stack->head - 1 + stack->capacity) % stack->capacity;
		source_idx = (stack->head + size - 1) % stack->capacity;
		stack->array[new_head] = stack->array[source_idx];
		stack->head = new_head;
	}
}
