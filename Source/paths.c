#include "../so_long.h"

char	*path(int c)
{
	char	*ret;

	ret = ft_strjoin("./assets/Spriter/tile0", "");
	if (!ret)
		return (NULL);
	ret = ft_strjoin(ret, ft_itoa(c));
	if (!ret)
		return (NULL);
	ret = ft_strjoin(ret, ".xpm");
	if (!ret)
		return (NULL);
	return (ret);
}
