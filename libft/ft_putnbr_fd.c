#include "libft.h"

void	ft_putnbr_fd(int n, int fd)
{
	char	ret;
	int		i;

	i = 1;
	ret = 0;
	if (n < 0)
	{
		i = -1;
		ft_putchar_fd('-', fd);
	}
	if (n / 10)
		ft_putnbr_fd(n / 10 * i, fd);
	ret = n % 10 * i + 48;
	ft_putchar_fd(ret, fd);
}
