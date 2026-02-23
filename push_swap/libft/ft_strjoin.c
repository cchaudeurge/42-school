/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strjoin.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cchaudeu <cchaudeu@student.42berlin.d      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/04 15:22:37 by cchaudeu          #+#    #+#             */
/*   Updated: 2025/06/06 16:46:14 by cchaudeu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strjoin(char const *s1, char const *s2)
{
	char	*joined;
	size_t	jsize;

	jsize = ft_strlen(s1) + ft_strlen(s2) + 1;
	joined = (char *)malloc(jsize);
	if (!joined)
		return (NULL);
	ft_strlcpy(joined, s1, jsize);
	ft_strlcat(joined, s2, jsize);
	return (joined);
}
