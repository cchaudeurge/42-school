#include "libft.h"

int	ft_max_abs(int a, int b)
{
	if (ft_abs(a) >= ft_abs(b))
		return (ft_abs(a));
	else
		return (ft_abs(b));
}
