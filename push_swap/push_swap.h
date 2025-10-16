/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cchaudeu <cchaudeu@student.42berlin.d      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/10 21:15:35 by cchaudeu          #+#    #+#             */
/*   Updated: 2025/10/15 14:52:02 by cchaudeu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

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
