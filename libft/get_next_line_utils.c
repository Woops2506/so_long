#include "libft.h"

size_t	ft_strleng(const char *s)
{
	size_t	c;

	c = 0;
	while (*s)
	{
		s++;
		c++;
	}
	return (c);
}

char	*ft_strjoing(char *s1, char *s2)
{
	size_t	i;
	size_t	c;
	char	*ret;

	i = -1;
	c = 0;
	if (!s1)
		return (ft_strdupg(s2));
	if (!s2)
		return (s1);
	ret = malloc((ft_strleng(s1) + ft_strleng(s2) + 1) * sizeof(char));
	if (!ret)
		return (free(s1), NULL);
	while (s1[++i] != '\0')
		ret[i] = s1[i];
	while (s2[c] != '\0')
		ret[i++] = s2[c++];
	ret[i] = '\0';
	return (free(s1), ret);
}

int	ft_strchrg(const char *s, int c)
{
	int	i;

	i = 0;
	if (!s)
		return (0);	
	while (s[i])
	{
		if (s[i] == (char)c)
			return (1);
		i++;
	}
	return (0);
}

char	*ft_strdupg(const char *s1)
{
	char	*ret;
	size_t	c;

	c = 0;
	ret = malloc(ft_strleng(s1) * sizeof(char) + 1);
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
