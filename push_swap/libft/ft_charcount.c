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
