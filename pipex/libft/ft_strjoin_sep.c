#include "libft.h"

char	*ft_strjoin_sep(char *str1, char *str2, char *separator)
{
	char	*temp;
	char	*result;

	if (!str1 || !str2)
		return NULL;
	temp = ft_strjoin(str1, separator);
	if (!temp)
		return NULL;
	result = ft_strjoin(temp, str2);
	free(temp);
	if (!result)
		return NULL;
	return (result);
}
