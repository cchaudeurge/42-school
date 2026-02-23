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


void	swap(t_sgroup *group, char identifier)
{
	t_stack *second_node;

	if (identifier == 's')
	{
		swap(group, 'a');
		swap(group, 'b');
	}
	else if (identifier == 'a' && group->a && (group->a)->next)
	{
		second_node = (group->a)->next;
		stackadd_front(&(group->a), second_node);
	}
	else if (identifier == 'b' && group->b && (group->b)->next)
	{
		second_node = (group->b)->next;
		stackadd_front(&(group->b), second_node); XXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXX try group.b without &
	}
}

/*Take the first element at the top of a stack and put it at the top of the
 * other stack. Do nothing if the first stack is empty. pa (push a) pushes the
 * first element at the top of b to a (push to a).*/

void	push(t_sgroup *group, char identifier)
{
	t_stack *node2push;

	if (identifier == 'a' && group->b)
	{
		node2push = group->b;
		group->b = node2push->next;
		stackadd_front(&(group->a), node2push);
	}
	else if (identifier == 'b' && group->a)
	{
		node2push = group->a;
		group->a = node2push->next;
		stackadd_front(&(group->b), node2push);
	}
}

/*Shift up all elements of a stack by 1.
 * The first element becomes the last one.*/

void	rotate(t_sgroup *group, char identifier)
{
	t_stack	*node2move;

	if (identifier == 'r')
	{
		rotate(group, 'a');
		rotate(group, 'b');
	}
	else if (identifier == 'a' && group->a && (group->a)->next)
	{
		node2move = group->a;
		group->a = (group->a)->next;
		stackadd_back(&(group->a), node2move);
	}
	else if (identifier == 'b' && group->b && (group->b)->next)
	{
		node2move = group->b;
		group->b = (group->b)->next;
		stackadd_back(&(group->b), node2move);
	}
}

/*Shift down all elements of a stack by 1.
 * The last element becomes the first one.*/

void	revrotate(t_group *group, char identifier)
{
	t_stack	*node2move;

	if (identifier == 'r')
	{
		revrotate(group, 'a');
		revrotate(group, 'b');
	}
	else if (identifier == 'a' && group->a && (group->a)->next)
	{
		node2move = getlast(group->a);
		stackadd_front(&(group->a), node2move);
	}
	else if (identifier == 'b' && group->b && (group->b)->next)
	{
		node2move = getlast(group->b);
		stackadd_front(&(group->b), node2move);
	}
}
