/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_itoa.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cchaudeu <cchaudeu@student.42berlin.d      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/06 17:59:42 by cchaudeu          #+#    #+#             */
/*   Updated: 2025/06/10 00:30:13 by cchaudeu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static char	*fill_nb_str(char *str, int n, int div_max, int sign)
{
	int	i;

	i = 0;
	if (sign)
	{
		str[i] = '-';
		i++;
	}
	while (div_max >= 1)
	{
		str[i] = n / div_max + '0';
		n %= div_max;
		div_max /= 10;
		i++;
	}
	return (str);
}

char	*ft_itoa(int n)
{
	int		length;
	int		div_max;
	char	*nb_str;
	int		sign;

	if (n == -2147483648)
		return (ft_strdup("-2147483648"));
	length = 1;
	div_max = 1;
	sign = 0;
	if (n < 0)
	{
		length++;
		sign = 1;
		n = -n;
	}
	while (n / div_max > 9)
	{
		length++;
		div_max *= 10;
	}
	nb_str = (char *)ft_calloc((size_t)(length + 1), sizeof(char));
	if (!nb_str)
		return (NULL);
	return (fill_nb_str(nb_str, n, div_max, sign));
}
