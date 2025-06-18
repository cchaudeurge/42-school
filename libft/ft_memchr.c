/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memchr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cchaudeu <cchaudeu@student.42berlin.d      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/03 00:55:37 by cchaudeu          #+#    #+#             */
/*   Updated: 2025/06/03 02:37:44 by cchaudeu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memchr(const void *ptr, int c, size_t n)
{
	const unsigned char	*pointer;

	pointer = (const unsigned char *)ptr;
	while (n--)
	{
		if (*pointer == (unsigned char)c)
			return ((void *)pointer);
		pointer++;
	}
	return (NULL);
}
