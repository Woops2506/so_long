#include "libft.h"

char	*ft_strnstr(const char *haystack, const char *needle, size_t len)
{
	size_t	c;
	size_t	i;

	c = 0;
	i = 0;
	if (!needle && !haystack)
		return (NULL);
	if (!needle[c])
		return ((char *)haystack);
	while (haystack[i] && i < len)
	{
		c = 0;
		while (haystack[i + c] == needle[c] && (c + i) < len
			&& needle[c] && haystack[i + c])
		{
			c++;
		}
		if (needle[c] == '\0')
			return ((char *)(haystack + i));
		i++;
	}
	return (NULL);
}
