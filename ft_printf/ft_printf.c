/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cchaudeu <cchaudeu@student.42berlin.d      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/25 13:52:24 by cchaudeu          #+#    #+#             */
/*   Updated: 2025/07/01 22:10:51 by cchaudeu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

/*for variadic function macros*/
#include <stdarg.h>
/*for uintptr_t*/
#include <stdint.h>
#include <stdio.h>
#include <unistd.h>
/*for testing with strchr*/
#include <string.h>

int	printargument(va_list *argsptr, char c);
int	printchar(char c);
int printstr(char *str);
int printvptr (void *ptr);
int printdecimal (int nb);
int print_in_base(uintptr_t nb, char *str, int *printed, uintptr_t base);

int	ft_printf(const char *fstr, ...)
{
	va_list	args;
	va_list	*argsptr;
	int		char_count;

	char_count = 0;
	va_start(args, fstr);
	argsptr = &args;
	while (*fstr)
	{
		if (*fstr != '%')
			char_count += printchar(*fstr);
		else if (*fstr++ == '%')
		{
			if (*fstr && strchr("cspdiuxX%", *fstr))
				char_count += printargument(argsptr, *fstr);
			else
				return (0);
		}
	   fstr++;	
	}
	va_end(args);
	return (char_count);
}

int	printargument(va_list *argsptr, char c)
{
	int	char_count;

	char_count = 0;
	if (c == 'c')
	   return (printchar(va_arg(*argsptr, char)));
	if (c == 's')
		return (printstr(va_arg(*argsptr, char *)));
	if (c == 'p')
		return (printvptr(va_arg(*argsptr, void *)));
	if (c == 'd' || c == 'i')
		return (printdecimal(va_arg(*argsptr, int)));
	if (c == 'u')
		return (printdecimal((int)va_arg(*argsptr, unsigned int)));
	if (c == 'x')
		return (print_in_base((uintptr_t)va_arg(*argsptr, unsigned int),
					"0123456789abcdef", &char_count, 16));
	if (c == 'X')
		return (print_in_base((uintptr_t)va_arg(*argsptr, unsigned int),
					"0123456789ABCDEF", &char_count, 16));
	if (c == '%')
		return (printchar('%'));
}

int	printchar(char c)
{
	write(1, &c, 1);
	return (1);
}

int printstr(char *str)
{
	int	char_count;

	char_count = 0;
	while (*str)
	{
		write(1, str, 1);
		str++;
		char_count++;
	}
	return (char_count);
}

int printvptr (void *ptr)
{
	uintptr_t	address;
	int			char_count;

	address	= (uintptr_t)ptr;
	write(1, "0x", 2);
	char_count = 2;
	return (print_in_base(address, "0123456789abcdef", &char_count, 16));
}

int printdecimal (int nb)
{
	int	char_count;

	char_count = 0;
	if (nb < 0)
	{
		write(1, "-", 1);
		char_count++;
	}
	return (print_in_base((uintptr_t)nb, "0123456789", &char_count, 10));
}

int print_in_base(uintptr_t nb, char *str, int *printed, uintptr_t base)
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
