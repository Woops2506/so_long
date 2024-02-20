#include "../so_long.h"

void	map_to_terminal(t_map map)
{
	int	c;

	c = 0;
	if (!map.map)
		return ;
	if (!*map.map)
		return ;
	while (map.map[c])
	{
		printf("%s\n", map.map[c]);
		c++;
	}
}

int	main(int argc, char *argv[])
{
	t_map	map;
	int		error;

	error = 0;
	if (argc < 2)
	{
		wall_error(-4);
		return (0);
	}
	error = start_check(&map, argv);
	if (error < 0)
	{
		wall_error(error);
		return (0);
	}
	map_to_terminal(map);
	map_init(map);
	freemap(&map);
}

//	start_game(&map);