/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cchaudeu <cchaudeu@student.42berlin.d      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/26 15:34:27 by cchaudeu          #+#    #+#             */
/*   Updated: 2025/06/26 17:30:41 by cchaudeu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

typedef struct	s_formatspec
{
	char	identifier;
	void	*value;
	int		length;
	int		precision;
	int		width;
	int		ljust;


}				t_formatspec;
