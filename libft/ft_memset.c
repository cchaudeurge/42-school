/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memset.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cchaudeu <cchaudeu@student.42berlin.d      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/28 19:01:57 by cchaudeu          #+#    #+#             */
/*   Updated: 2025/05/30 18:15:28 by cchaudeu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memset(void *pointer, int value, size_t number)
{
	unsigned char	*ptr;
	unsigned char	val;

	ptr = (unsigned char *)pointer;
	val = (unsigned char)value;
	while (number--)
		*(ptr++) = val;
	return (pointer);
}
