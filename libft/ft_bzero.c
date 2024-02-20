#include "libft.h"

void	ft_bzero(void *s, size_t n)
{
	size_t	c;

	c = 0;
	while (c < n)
	{
		(*(unsigned char *)(s + c)) = '\0';
		c++;
	}
}
