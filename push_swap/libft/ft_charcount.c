/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_charcount.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cchaudeu <cchaudeu@student.42berlin.d      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/03/18 20:29:42 by cchaudeu          #+#    #+#             */
/*   Updated: 2026/03/18 20:29:45 by cchaudeu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

size_t	ft_charcount(char *s, char c)
{
	size_t	char_count;
	int		i;

	char_count = 0;
	i = 0;
	while (s[i])
	{
		if (s[i] == c)
			char_count++;
		i++;
	}
	return (char_count);
}
