#include "libft.h"

char	*ft_strmapi(char const *s, char (*f)(unsigned int, char))
{
	char			*ret;
	unsigned int	c;

	c = 0;
	ret = malloc(ft_strlen(s) * sizeof(char) + 1);
	if (!ret)
		return (0);
	while (s[c])
	{
		ret[c] = (*f)(c, s[c]);
		c++;
	}
	ret[c] = '\0';
	return (ret);
}
