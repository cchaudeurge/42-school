/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   lists.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cchaudeu <cchaudeu@student.42berlin.d      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/17 13:43:40 by cchaudeu          #+#    #+#             */
/*   Updated: 2025/10/17 16:05:58 by cchaudeu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

/*Returns a pointer to the last node of the list pointed to by the pointer
 * passed as a parameter.*/

t_stack	*getlast(t_stack *stack)
{
	t_stack	*last_node;

	if (!stack)
		return (NULL);
	last_node = stack;
	while (last_node->next)
		last_node = last_node->next;
	return (last_node);
}

/*Adds the node passed as a parameter at the front (first node) of the list
 * passed as a parameter (through a double pointer). The pointer to the list is
 * updated. If the node was already part of a list, it is removed from it
 * without breaking the list.*/

void	stackadd_front(t_stack **stack, t_stack *new)
{
	t_stack	previous_node;
	t_stack	next_node;

	if (!stack || !new)
		return ;
	previous_node = new->prev;
	next_node = new->next;
	if (previous_node)
		previous_node->next = new->next;
	if (next_node)
		next_node->prev = new->prev
	if (*stack)
		*stack->prev = new;
	new->next = *stack;
	new->prev = NULL;
	*stack = new;
}

/*Adds the node passed as a parameter at the back (last node) of the list
 * passed as a parameter (through a double pointer). If the list was empty (NULL
 * ptr), the list is "created" and the pointer to the list is
 * updated. If the node was already part of a list, it is removed from it
 * without breaking the list.*/

void	stackadd_back(t_stack **stack, t_stack *new)
{
	t_stack	previous_node;
	t_stack	next_node;

	if (!stack || !new)
		return ;
	previous_node = new->prev;
	next_node = new->next;
	if (previous_node)
		previous_node->next = new->next;
	if (next_node)
		next_node->prev = new->prev
	if (*stack)
	{
		getlast(*stack)->next = new;
		new->prev = getlast(*stack);
	}
	else
	{
		*stack = new;
		new->prev = NULL;
	}
	new->next = NULL;
}
