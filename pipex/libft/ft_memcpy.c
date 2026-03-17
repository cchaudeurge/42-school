/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memcpy.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cchaudeu <cchaudeu@student.42berlin.d      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/30 18:32:55 by cchaudeu          #+#    #+#             */
/*   Updated: 2025/06/10 21:25:42 by cchaudeu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memcpy(void *destination, const void *source, size_t nbr)
{
	unsigned char		*dest;
	const unsigned char	*src;

	if (!destination && !source)
		return (NULL);
	dest = (unsigned char *)destination;
	src = (const unsigned char *)source;
	while (nbr--)
		*(dest++) = *(src++);
	return (destination);
}
