#include "libft.h"

char	*ft_strdup(const char *s1)
{
	char	*ret;
	size_t	c;

	c = 0;
	ret = malloc(ft_strlen(s1) * sizeof(char) + 1);
	if (!ret)
		return (0);
	while (s1[c])
	{
		ret[c] = s1[c];
		c++;
	}
	ret[c] = '\0';
	return (ret);
}
