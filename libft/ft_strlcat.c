#include "libft.h"

size_t	ft_strlcat(char *dst, const char *src, size_t size)
{
	size_t	c;
	size_t	i;
	size_t	len;

	c = 0;
	i = 0;
	len = ft_strlen(dst);
	while (dst[c])
		c++;
	if (c < (size - 1) && size > 0)
	{
		while (src[i] && (len + i) < (size - 1))
			dst[c++] = src[i++];
		dst[c] = '\0';
	}
	while (src[i])
		i++;
	if (len >= size)
		len = size;
	return (len + i);
}
