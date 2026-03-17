/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memcmp.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cchaudeu <cchaudeu@student.42berlin.d      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/03 01:18:40 by cchaudeu          #+#    #+#             */
/*   Updated: 2025/06/03 02:36:22 by cchaudeu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	ft_memcmp(const void *s1, const void *s2, size_t n)
{
	const unsigned char	*s1_bis;
	const unsigned char	*s2_bis;

	s1_bis = (const unsigned char *)s1;
	s2_bis = (const unsigned char *)s2;
	while (n--)
	{
		if (*s1_bis != *s2_bis)
			return ((unsigned char)*s1_bis - (unsigned char)*s2_bis);
		s1_bis++;
		s2_bis++;
	}
	return (0);
}
