/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_calloc.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cchaudeu <cchaudeu@student.42berlin.d      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/03 15:41:30 by cchaudeu          #+#    #+#             */
/*   Updated: 2025/06/03 18:40:42 by cchaudeu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_calloc(size_t nbr, size_t size)
{
	void	*ptr;

	if (nbr == 0 || size == 0)
		return (malloc(0));
	if (nbr > SIZE_MAX / size)
		return (NULL);
	ptr = malloc(nbr * size);
	if (ptr == NULL)
		return (NULL);
	ft_bzero(ptr, nbr * size);
	return (ptr);
}
