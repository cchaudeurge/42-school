/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memmove.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cchaudeu <cchaudeu@student.42berlin.d      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/30 19:17:07 by cchaudeu          #+#    #+#             */
/*   Updated: 2025/06/02 20:36:41 by cchaudeu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memmove(void *destination, const void *source, size_t nbr)
{
	unsigned char		*dest;
	const unsigned char	*src;
	size_t				i;

	dest = (unsigned char *)destination;
	src = (const unsigned char *)source;
	if (destination < source)
	{
		i = 0;
		while (i < nbr)
		{
			dest[i] = src[i];
			i++;
		}
	}
	else if (destination > source)
	{
		i = nbr;
		while (i > 0)
		{
			i--;
			dest[i] = src[i];
		}
	}
	return (destination);
}
