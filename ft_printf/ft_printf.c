/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cchaudeu <cchaudeu@student.42berlin.d      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/04 18:51:32 by cchaudeu          #+#    #+#             */
/*   Updated: 2025/07/04 19:24:42 by cchaudeu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	ft_printf(const char *fstr, ...)
{
	va_list	args;
	va_list	*argsptr;
	int		char_count;
	int		i;

	i = 0;
	char_count = 0;
	va_start(args, fstr);
	argsptr = &args;
	while (fstr[i])
	{
		if (fstr[i] == '%' && is_in_set(fstr[i + 1], "cspdiuxX%"))
		{
			char_count += printargument(argsptr, fstr[i + 1]);
			i += 2;
		}
		else
		{
			char_count += printchar(fstr[i]);
			i++;
		}
	}
	va_end(args);
	return (char_count);
}

int	is_in_set(char c, char *set)
{
	int	i;

	i = 0;
	while (set[i])
	{
		if (c == set[i])
			return (1);
		i++;
	}
	return (0);
}

int	printargument(va_list *argsptr, char c)
{
	int	char_count;

	char_count = 0;
	if (c == 'c')
		return (printchar(va_arg(*argsptr, int)));
	else if (c == 's')
		return (printstr(va_arg(*argsptr, char *)));
	else if (c == 'p')
		return (printvptr(va_arg(*argsptr, void *)));
	else if (c == 'd' || c == 'i')
		return (printdecimal(va_arg(*argsptr, int)));
	else if (c == 'u')
		return (printdecimal((int)va_arg(*argsptr, unsigned int)));
	else if (c == 'x')
		return (print_in_base((uintptr_t)va_arg(*argsptr, unsigned int),
				"0123456789abcdef", &char_count, 16));
	else if (c == 'X')
		return (print_in_base((uintptr_t)va_arg(*argsptr, unsigned int),
				"0123456789ABCDEF", &char_count, 16));
	else if (c == '%')
		return (printchar('%'));
	else
		return (char_count);
}
