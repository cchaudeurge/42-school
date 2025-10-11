/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cchaudeu <cchaudeu@student.42berlin.d      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/10 21:15:35 by cchaudeu          #+#    #+#             */
/*   Updated: 2025/10/11 02:23:21 by cchaudeu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

/*Double-linked list*/
typedef struct s_stack
{
	int				nbr;
	int				indx;
	struct s_stack	*prev;
	struct s_stack	*next;
}					t_stack;

