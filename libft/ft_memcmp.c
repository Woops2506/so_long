#include "libft.h"

int	ft_memcmp(const void *s1, const void *s2, size_t n)
{
	size_t	i;

	i = 0;
	if (n == 0)
		return (0);
	while (i < n)
	{
		if ((*(unsigned char *)s1) != (*(unsigned char *)s2))
			return (((*(unsigned char *)s1) - (*(unsigned char *)s2)));
		s1++;
		s2++;
		i++;
	}
	if (i == n)
	{
		s1--;
		s2--;
	}
	return (((*(unsigned char *)s1) - (*(unsigned char *)s2)));
}
