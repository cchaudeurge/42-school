/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cchaudeu <cchaudeu@student.42berlin.d      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/26 15:34:27 by cchaudeu          #+#    #+#             */
/*   Updated: 2025/07/18 21:12:56 by cchaudeu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

/*ft_printf.h*/

#ifndef FT_PRINTF_H
# define FT_PRINTF_H

/*for variadic function macros*/
# include <stdarg.h>
/*for uintptr_t*/
# include <stdint.h>
/*for write*/
# include <unistd.h>

/*Function Prototypes*/

/*ft_printf.c*/
int	ft_printf(const char *fstr, ...);
int	is_in_set(char c, char *set);
int	printargument(va_list *argsptr, char c);

/*printing_types.c*/
int	printchar(int c);
int	printstr(char *str);
int	printvptr(void *ptr);
int	printdecimal(int nb);
int	print_in_base(uintptr_t nb, char *str, int *printed, uintptr_t base);

#endif
