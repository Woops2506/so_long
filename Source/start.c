#include "../so_long.h"

int	start_check(t_map *map, char *argv[])
{
	int		fd;
	char	**visited;

	fd = open(argv[1], O_RDONLY);
	map->rows = linecount(fd) + 1;
	printf("%i\n", map->rows);
	close(fd);
	fd = open(argv[1], O_RDONLY);
	visited = fill_map(map, fd);
	close(fd);
	if (!visited || !*map->map || !*visited)
		return (-6);
	if (!line_check(map))
		return (freevisited(visited, map), -1);
	map->collums = ft_strlen(map->map[1]);
	if (!wall_check(map))
		return (freevisited(visited, map), -2);
	if (!p_e_check(map))
		return (freevisited(visited, map), -5);
	player_position(map);
	map->collectables = count_collectables(map);
	visited[map->player.c][map->player.i] = 'V';
	if (!solve_level(visited, map))
		return (-3);
	freevisited(visited, map);
	return (1);
}

int	map_init(t_map map)
{
	t_data	data;

	data.mlx_ptr = mlx_init();
	data.map = map;
	data.steps = 0;
	if (!data.mlx_ptr)
		return (0);
	control(&data);
	return (1);
}
