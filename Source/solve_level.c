#include "../so_long.h"

char	explore_surroundings(char c, t_map *map)
{
	printf("COUNTER: %i\n", map->testcounter);
	if (c == 'C' || c == 'E')
		map->testcounter += 1;
	if (c == '0' || c == 'C' || c == 'E')
		return (c);
	return ('1');
}

void	pathfinder(char **visited, int c, int i, t_map *map)
{
	char	checking_top;
	char	checking_bot;
	char	checking_left;
	char	checking_right;

	checking_top = explore_surroundings(visited[c - 1][i], map);
	if (checking_top == '0' || checking_top == 'C' || checking_top == 'E')
		visited[c - 1][i] = 'V';
	checking_bot = explore_surroundings(visited[c + 1][i], map);
	if (checking_bot == '0' || checking_bot == 'C' || checking_bot == 'E')
		visited[c + 1][i] = 'V';
	checking_left = explore_surroundings(visited[c][i - 1], map);
	if (checking_left == '0' || checking_left == 'C' || checking_left == 'E')
		visited[c][i - 1] = 'V';
	checking_right = explore_surroundings(visited[c][i + 1], map);
	if (checking_right == '0' || checking_right == 'C' || checking_right == 'E')
		visited[c][i + 1] = 'V';
}

int	deadend(char **visited, int c, int i, t_map *map)
{
	char	checking_top;
	char	checking_bottom;
	char	checking_left;
	char	checking_right;

	checking_top = visited[c - 1][i];
	checking_bottom = visited[c + 1][i];
	checking_right = visited[c][i + 1];
	checking_left = visited[c][i - 1];
	if ((checking_bottom == '1' || checking_bottom == 'V')
		&& (checking_top == '1' || checking_top == 'V')
		&& (checking_left == '1' || checking_left == 'V')
		&& (checking_right == '1' || checking_right == 'V'))
		return (1);
	pathfinder(visited, c, i, map);
	return (0);
}

int	iterate_map(char **visited, t_map *map, int i, int c)
{
	int dead_ends;

	dead_ends = 1;
	while (dead_ends != 0)
	{
		dead_ends = 0;
		c = 1;
		while (c < map->rows - 1)
		{
			i = 1;
			while (i < map->collums - 1)
			{
				if (visited[c][i] == 'V')
					if (!deadend(visited, c, i, map))
						dead_ends = 1;
				i++;
			}
			c++;
		}
	}
	if (map->testcounter == (map->collectables + 1))
		return (1);
	return (0);
}

int	solve_level(char **visited, t_map *map)
{
	int	i;
	int	c;

	i = 0;
	c = 0;
	map->testcounter = 0;
	if (iterate_map(visited, map, i, c))
		return (1);
	freevisited(visited, map);
	freemap(map);
	return (0);
}
