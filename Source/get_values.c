#include "../so_long.h"

int	linecount(int fd)
{
	int		c;
	int		i;
	char	*tmp;

	i = 1;
	c = 0;
	tmp = ft_calloc(BUFFER_SIZE, sizeof(char) + 1);
	while (i > 0)
	{
		i = read(fd, tmp, BUFFER_SIZE);
		if (i == -1)
			return (-1);
		tmp[i] = '\0';
		if (ft_strchr(tmp, '\n'))
			c++;
	}
	free(tmp);
	return (c);
}

int	count_collectables(t_map *map)
{
	int	co;
	int	c;
	int	i;

	c = 0;
	co = 0;
	while (map->map[c])
	{
		i = 0;
		while (map->map[c][i])
		{
			if (map->map[c][i] == 'C')
				co++;
			i++;
		}
		c++;
	}
	return (co);
}

void	player_position(t_map *map)
{
	int	c;
	int	i;

	c = 0;
	while (map->map[c])
	{
		i = 0;
		while (map->map[c][i])
		{
			if (map->map[c][i] == 'P')
			{
				map->player.c = c;
				map->player.i = i;
				return ;
			}
			i++;
		}
		c++;
	}
}
