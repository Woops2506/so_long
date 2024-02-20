#include "libft.h"

void	*ft_memcpy(void *dest, const void *src, size_t n)
{
	size_t	c;

	c = 0;
	if (!dest && !src)
		return (0);
	while (c < n)
	{
		(*(unsigned char *)(dest + c)) = (*(unsigned char *)(src + c));
		c++;
	}
	return (dest);
}
