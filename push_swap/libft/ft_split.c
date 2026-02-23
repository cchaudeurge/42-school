/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_split.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cchaudeu <cchaudeu@student.42berlin.d      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/05 18:53:29 by cchaudeu          #+#    #+#             */
/*   Updated: 2025/06/06 17:20:08 by cchaudeu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static size_t	count_words(char const *str, char c)
{
	size_t	wordcount;
	size_t	i;

	wordcount = 0;
	i = 0;
	while (str[i])
	{
		if (str[i] != c && (str[i + 1] == c || !str[i + 1]))
			wordcount++;
		i++;
	}
	return (wordcount);
}

static void	*free_all(char **substr_array, unsigned int i)
{
	while (i--)
		free(substr_array[i]);
	free(substr_array);
	return (NULL);
}

static char	**fill_array(char const *str, char c, char **substr_array)
{
	unsigned int	start;
	unsigned int	end;
	unsigned int	i;
	size_t			wordcount;

	wordcount = count_words(str, c);
	end = 0;
	i = 0;
	while (wordcount--)
	{
		while (str[start] == c)
			start++;
		end = start;
		while (str[end] && str[end] != c)
			end++;
		substr_array[i] = ft_substr(str, start, end - start);
		start = end;
		i++;
		if (!substr_array[i - 1])
			return (free_all(substr_array, i));
	}
	return (substr_array);
}

char	**ft_split(char const *s, char c)
{
	char			**words;

	if (!s)
		return (NULL);
	words = (char **)ft_calloc(count_words(s, c) + 1, sizeof(char *));
	if (!words)
		return (NULL);
	words = fill_array(s, c, words);
	return (words);
}
