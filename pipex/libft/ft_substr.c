/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_substr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cchaudeu <cchaudeu@student.42berlin.d      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/03 22:38:01 by cchaudeu          #+#    #+#             */
/*   Updated: 2025/06/10 22:32:36 by cchaudeu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_substr(char const *s, unsigned int start, size_t len)
{
	char			*substr;
	size_t			substrlen;

	if (start >= ft_strlen(s))
		return (ft_strdup(""));
	substrlen = ft_strlen(s + start);
	if (substrlen <= len)
		return (ft_strdup(s + start));
	else
	{
		substr = (char *)malloc(len + 1);
		if (!substr)
			return (NULL);
		ft_strlcpy(substr, s + start, len + 1);
		return (substr);
	}
}
