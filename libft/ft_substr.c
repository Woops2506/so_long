#include "libft.h"

static size_t	lencheck(char const *s, unsigned int start)
{
	size_t	i;
	size_t	t;

	i = 0;
	t = 0;
	while (s[t])
	{
		if (t >= start)
			i++;
		t++;
	}
	return (i);
}

char	*ft_substr(char const *s, unsigned int start, size_t len)
{
	size_t	c;
	size_t	i;
	char	*ret;

	c = lencheck(s, start);
	i = 0;
	if (len > c)
		len = c;
	c = 0;
	ret = malloc(len * sizeof(char) + 1);
	if (!ret)
		return (0);
	while (s[c])
	{
		if (c >= start && i < len)
			ret[i++] = s[c];
		c++;
	}
	ret[i] = '\0';
	return (ret);
}
