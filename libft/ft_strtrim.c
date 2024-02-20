#include "libft.h"

static int	iteristr(char s1, char const *set)
{
	int	c;

	c = 0;
	while (set[c])
	{
		if (s1 == set[c])
			return (1);
		c++;
	}
	return (0);
}

char	*ft_strtrim(char const *s1, char const *set)
{
	char	*ret;
	int		len;
	int		c;
	int		i;

	c = 0;
	i = 0;
	len = ft_strlen(s1);
	while (iteristr(s1[c], set) && s1[c])
		c++;
	while (iteristr(s1[len - 1], set) && c < len)
		len--;
	ret = malloc((len + 1 - c) * sizeof(char));
	if (!ret)
		return (NULL);
	while (s1[c] && c < len)
		ret[i++] = s1[c++];
	ret[i] = '\0';
	return (ret);
}
