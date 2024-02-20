#include "libft.h"

void	ft_striteri(char *s, void (*f)(unsigned int, char*))
{
	unsigned int	c;

	c = 0;
	if (!s)
		return ;
	while (s[c])
	{
		f(c, &s[c]);
		c++;
	}
}
