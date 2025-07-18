/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   printing_types.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cchaudeu <cchaudeu@student.42berlin.d      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/04 19:07:05 by cchaudeu          #+#    #+#             */
/*   Updated: 2025/07/18 17:01:30 by cchaudeu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	printchar(int c)
{
	write(1, &c, 1);
	return (1);
}

int	printstr(char *str)
{
	int	char_count;

	char_count = 0;
	if (!str)
	{
		write(1, "(null)", 6);
		return (6);
	}
	while (*str)
	{
		write(1, str, 1);
		str++;
		char_count++;
	}
	return (char_count);
}

int	printvptr(void *ptr)
{
	uintptr_t	address;
	int			char_count;

	if (!ptr)
		return (printstr("(nil)"));
	address = (uintptr_t)ptr;
	write(1, "0x", 2);
	char_count = 2;
	return (print_in_base(address, "0123456789abcdef", &char_count, 16));
}

int	printdecimal(int nb)
{
	int	char_count;

	if (nb == -2147483648)
		return (printstr("-2147483648"));
	char_count = 0;
	if (nb < 0)
	{
		write(1, "-", 1);
		char_count++;
		nb = -nb;
	}
	return (print_in_base((uintptr_t)nb, "0123456789", &char_count, 10));
}

int	print_in_base(uintptr_t nb, char *str, int *printed, uintptr_t base)
{
	if (nb / base == 0)
	{
		write(1, &str[nb % base], 1);
		(*printed)++;
	}
	else
	{
		print_in_base(nb / base, str, printed, base);
		write(1, &str[nb % base], 1);
		(*printed)++;
	}
	return (*printed);
}
