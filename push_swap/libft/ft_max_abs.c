/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_max_abs.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cchaudeu <cchaudeu@student.42berlin.d      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/03/18 20:31:47 by cchaudeu          #+#    #+#             */
/*   Updated: 2026/03/18 20:31:51 by cchaudeu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	ft_max_abs(int a, int b)
{
	if (ft_abs(a) >= ft_abs(b))
		return (ft_abs(a));
	else
		return (ft_abs(b));
}
