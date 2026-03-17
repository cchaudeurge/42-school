/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putnbr_fd.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cchaudeu <cchaudeu@student.42berlin.d      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/09 22:20:10 by cchaudeu          #+#    #+#             */
/*   Updated: 2025/06/10 00:36:12 by cchaudeu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_putnbr_fd(int n, int fd)
{
	int		div_max;
	char	to_print;

	if (n == -2147483648)
	{
		write(fd, "-2147483648", 11);
		return ;
	}
	div_max = 1;
	to_print = 0;
	if (n < 0)
	{
		write(fd, "-", 1);
		n = -n;
	}
	while (n / div_max > 9)
		div_max *= 10;
	while (div_max >= 1)
	{
		to_print = n / div_max + '0';
		write(fd, &to_print, 1); 
		n %= div_max;
		div_max /= 10;
	}
}
