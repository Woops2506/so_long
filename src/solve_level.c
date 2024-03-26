/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   solve_level.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mareurin <mareurin@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/18 18:33:42 by mareurin          #+#    #+#             */
/*   Updated: 2024/03/20 14:49:34 by mareurin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../so_long.h"

char	explore_surroundings(char c, t_data *data)
{
	if (c == 'C' || c == 'E')
		data->map.testcounter += 1;
	if (c == '0' || c == 'C' || c == 'E')
		return (c);
	return ('1');
}

void	pathfinder(char **test_map, int c, int i, t_data *data)
{
	char	checking_top;
	char	checking_bot;
	char	checking_left;
	char	checking_right;

	checking_top = explore_surroundings(test_map[c - 1][i], data);
	if (checking_top == '0' || checking_top == 'C' || checking_top == 'E')
		test_map[c - 1][i] = 'V';
	checking_bot = explore_surroundings(test_map[c + 1][i], data);
	if (checking_bot == '0' || checking_bot == 'C' || checking_bot == 'E')
		test_map[c + 1][i] = 'V';
	checking_left = explore_surroundings(test_map[c][i - 1], data);
	if (checking_left == '0' || checking_left == 'C' || checking_left == 'E')
		test_map[c][i - 1] = 'V';
	checking_right = explore_surroundings(test_map[c][i + 1], data);
	if (checking_right == '0' || checking_right == 'C' || checking_right == 'E')
		test_map[c][i + 1] = 'V';
}

int	deadend(char **test_map, int c, int i, t_data *data)
{
	char	checking_top;
	char	checking_bottom;
	char	checking_left;
	char	checking_right;

	checking_top = test_map[c - 1][i];
	checking_bottom = test_map[c + 1][i];
	checking_right = test_map[c][i + 1];
	checking_left = test_map[c][i - 1];
	if ((checking_bottom == '1' || checking_bottom == 'V')
		&& (checking_top == '1' || checking_top == 'V')
		&& (checking_left == '1' || checking_left == 'V')
		&& (checking_right == '1' || checking_right == 'V'))
		return (1);
	pathfinder(test_map, c, i, data);
	return (0);
}

int	iterate_map(char **test_map, t_data *data, int i, int c)
{
	int	dead_ends;

	dead_ends = 1;
	while (dead_ends != 0
		&& data->map.testcounter != (data->map.collectables + 1))
	{
		dead_ends = 0;
		c = 1;
		while (c < data->map.rows - 1)
		{
			i = 1;
			while (i < data->map.collums - 1)
			{
				if (test_map[c][i] == 'V')
					if (!deadend(test_map, c, i, data))
						dead_ends = 1;
				i++;
			}
			c++;
		}
	}
	if (data->map.testcounter == (data->map.collectables + 1))
		return (1);
	return (0);
}

int	solve_level(char **test_map, t_data *data)
{
	int	i;
	int	c;

	i = 0;
	c = 0;
	data->map.testcounter = 0;
	if (iterate_map(test_map, data, i, c))
		return (1);
	return (0);
}
