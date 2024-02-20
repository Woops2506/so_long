#include "../so_long.h"

int	p_e_check(t_map *map)
{
	int	c;
	int	i;
	int	p;
	int	e;

	c = 0;
	i = 0;
	p = 0;
	e = 0;
	while (map->map[c])
	{
		while (map->map[c][i])
		{
			if (map->map[c][i] == 'P')
				p++;
			if (map->map[c][i] == 'E')
				e++;
			i++;
		}
		i = 0;
		c++;
	}
	if (p == 1 && e == 1)
		return (1);
	return (freemap(map), 0);
}

char	**create_map(t_map *map, char **visited, int fd)
{
	char	*tmp;
	int		c;

	c = 0;
	tmp = ft_calloc(BUFFER_SIZE + 1, sizeof(char));
	while (c < map->rows)
	{
		tmp = get_next_line(fd);
		if (tmp)
		{
			map->map[c] = ft_strdup(tmp);
			map->map[c] = ft_strtrim(map->map[c], "\n");
			if (!map->map)
				return (0);
			visited[c] = ft_strdup(tmp);
			if (!visited)
				return (0);
		}
		c++;
	}
	free(tmp);
	return (visited);
}

char	**fill_map(t_map *map, int fd)
{
	char	**visited;

	map->map = ft_calloc((map->rows + 1), sizeof(char *));
	if (!map->map)
		return (NULL);
	visited = ft_calloc((map->rows + 1), sizeof(char *));
	if (!visited)
		return (NULL);
	visited = create_map(map, visited, fd);
	return (visited);
}

int	line_check(t_map *map)
{
	size_t	len;
	int		c;

	c = 0;
	len = ft_strlen(map->map[c]);
	while (map->map[c])
	{
		if (len != ft_strlen(map->map[c]))
			return (0);
		c++;
	}
	if (!map->map[c])
		return (1);
	freemap(map);
	return (0);
}

int	wall_check(t_map *map)
{
	int	c;
	int	i;

	c = 0;
	i = 0;
	while (c < map->rows)
	{
		while (i < map->collums - 1)
		{
			if (c == 0 || c == (map->rows - 1) || i == 0
				|| i == (map->collums - 1))
			{
				if (map->map[c][i] != '1')
					return (freemap(map), 0);
			}
			i++;
		}
		c++;
	}
	return (1);
}
