#include "libft.h"

int	ft_atoi(const char *str)
{
	long	ret;
	int		c;

	ret = 0;
	c = 1;
	while (*str == ' ' || (*str >= 9 && *str <= 13))
		str++;
	if (*str == '-')
	{
		c = -1;
		str++;
	}
	else if (*str == '+')
		str++;
	while (*str >= '0' && *str <= '9')
	{
		ret = ret * 10 + c * (*str - 48);
		if (ret > 2147483647)
			return (-1);
		else if (ret < -2147483648)
			return (0);
		str++;
	}
	return ((int)ret);
}
