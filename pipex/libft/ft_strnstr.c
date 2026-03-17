/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strnstr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cchaudeu <cchaudeu@student.42berlin.d      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/03 02:38:21 by cchaudeu          #+#    #+#             */
/*   Updated: 2025/06/03 15:41:07 by cchaudeu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strnstr(const char *big, const char *small, size_t len)
{
	size_t	i;
	size_t	j;

	if (!*small)
		return ((char *)big);
	i = 0;
	while (big[i])
	{
		j = 0;
		while (big[i + j] == small[j] && small[j] && i + j < len)
			j++;
		if (!small[j])
			return ((char *)&big[i]);
		i++;
	}
	return (NULL);
}
