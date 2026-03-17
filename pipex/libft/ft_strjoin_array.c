#include "libft.h"

char	*ft_strjoin_array(char **array, char *separator)
{
	int		i;
	char	*temp;
	char	*result;

	if (!array || !array[0])
		return NULL;
	result = ft_strdup(array[0]);
	if (!array[1])
		return (ft_strdup(array[0]);
	i = 1;
	while (array[i])
	{
		temp = ft_strjoin(result, separator);
		free(result);
		result = ft_strjoin(temp, array[i]);
		free(temp);
		i++;
	}
	return (result);
}
