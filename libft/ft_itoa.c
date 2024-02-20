#include "libft.h"

static int	intlen(int n)
{
	int	ret;

	ret = 0;
	if (n == -2147483648)
		return (11);
	if (n == 0)
		return (1);
	if (n < 0)
	{
		ret++;
		n *= -1;
	}
	while (n)
	{
		n = n / 10;
		ret++;
	}
	return (ret);
}

char	*ft_itoa(int n)
{
	char	*ret;
	int		len;

	len = intlen(n);
	if (n == -2147483648)
		return (ft_strdup("-2147483648"));
	ret = malloc((len + 1) * sizeof(char));
	if (!ret)
		return (NULL);
	if (n == 0)
		*ret = '0';
	if (n < 0)
	{
		n *= -1;
		*ret = '-';
	}
	ret[len--] = '\0';
	while (n)
	{
		ret[len--] = (n % 10) + 48;
		n = n / 10;
	}
	return (ret);
}
