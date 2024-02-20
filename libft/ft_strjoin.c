#include "libft.h"

char	*ft_strjoin(char const *s1, char const *s2)
{
	char	*ret;
	int		len;
	int		c;

	c = 0;
	len = ft_strlen(s1) + ft_strlen(s2) + 1;
	ret = malloc(len * sizeof(char));
	if (!ret)
		return (0);
	while (*s1)
	{
		ret[c++] = *s1;
		s1++;
	}
	while (*s2)
	{
		ret[c++] = *s2;
		s2++;
	}
	ret[c] = '\0';
	return (ret);
}
