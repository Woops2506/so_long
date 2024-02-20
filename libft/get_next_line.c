#include "libft.h"

char	*trim_buf(char *buf)
{
	char	*ret;
	int		c;
	int		t;

	c = 0;
	t = 0;
	while (buf[c] != '\n' && buf[c])
		c++;
	if (!buf[c])
		return (free(buf), NULL);
	c++;
	ret = malloc((ft_strleng(buf) - c + 1) * sizeof(char));
	if (!ret)
		return (free(buf), NULL);
	while (buf[c])
		ret[t++] = buf[c++]; 
	ret[t] = '\0';
	return (free(buf), ret);
}

char	*copy_ret(char *buf)
{
	char	*ret;
	int		c;

	c = 0;
	while (buf[c] != '\n' && buf[c])
		c++;
	ret = malloc((c + 2) * sizeof(char));
	if (!ret)
		return (NULL);
	c = 0;
	while (buf[c] != '\n' && buf[c])
	{
		ret[c] = buf[c];
		c++;
	}
	if (buf[c] == '\n')
		ret[c++] = '\n';
	ret[c] = '\0';
	return (ret);
}

char	*gnl_read(int fd, char *buf)
{
	char	*tmp;
	int		i;

	i = 1;
	tmp = malloc(BUFFER_SIZE * sizeof(char) + 1);
	if (!tmp)
		return (NULL);
	while (!ft_strchrg(buf, '\n') && i != 0)
	{
		i = read(fd, tmp, BUFFER_SIZE);
		if (i == -1)
			return (free(tmp), free(buf), NULL);
		tmp[i] = '\0';
		buf = ft_strjoing(buf, tmp);
		if (!buf)
			return (free(tmp), NULL);	
	}
	return (free(tmp), buf);
}

char	*get_next_line(int fd)
{
	static char	*buf;
	char		*ret;

	if (fd < 0 || BUFFER_SIZE <= 0)
		return (NULL);
	buf = gnl_read(fd, buf);
	if (!buf)
		return (NULL);
	ret = copy_ret(buf);
	if (!ret)
		return (NULL);
	buf = trim_buf(buf);
	return (ret);
}
