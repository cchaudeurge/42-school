/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strdup.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cchaudeu <cchaudeu@student.42berlin.d      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/03 22:13:38 by cchaudeu          #+#    #+#             */
/*   Updated: 2025/06/10 21:47:43 by cchaudeu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strdup(char const *str)
{
	char	*dupl;
	size_t	size;

	size = ft_strlen(str) + 1;
	dupl = (char *)malloc(size);
	if (!dupl)
		return (NULL);
	ft_strlcpy(dupl, str, size);
	return (dupl);
}
