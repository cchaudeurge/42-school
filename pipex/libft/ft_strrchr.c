/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strrchr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cchaudeu <cchaudeu@student.42berlin.d      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/02 23:19:08 by cchaudeu          #+#    #+#             */
/*   Updated: 2025/06/11 00:21:58 by cchaudeu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strrchr(const char *str, int c)
{
	size_t	pos;

	pos = ft_strlen(str);
	if ((char)c == '\0')
		return ((char *)(str + pos));
	while (pos > 0)
	{
		pos--;
		if (*(str + pos) == (char)c)
			return ((char *)(str + pos));
	}
	return (NULL);
}
