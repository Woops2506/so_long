#include "libft.h"

void	*ft_memchr(const void *s, int c, size_t n)
{
	size_t	i;

	i = 0;
	if (n == 0)
		return (NULL);
	while (i++ < n)
	{
		if (*(char *)s == (char)c)
			return ((void *)s);
		s++;
	}
	if ((char)c == '\0' && *(char *)(s + 1) == '\0')
		return ((void *)(s + 1));
	return (0);
}
