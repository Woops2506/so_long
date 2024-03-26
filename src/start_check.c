/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   start_check.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mareurin <mareurin@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/18 18:33:45 by mareurin          #+#    #+#             */
/*   Updated: 2024/03/25 17:38:03 by mareurin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../so_long.h"

int	map_valid(t_data *data, char **visited)
{
	map_to_terminal(data);
	if (!line_check(data))
		return (error("lines are not the same length", data), 0);
	if (!wall_check(data))
		return (error("Map not surounded by Walls", data), 0);
	if (!p_e_check(data))
		return (error("to many or to little Player or Exits", data), 0);
	if (!solve_level(visited, data))
		return (error("Player, Collectable or Exit surounded by Walls", data), 0);
	return (1);
}

int	start_check(t_data *data, char *argv[])
{
	int		fd;

	fd = open(argv[1], O_RDONLY);
	data->map.rows = linecount(fd) + 1;
	close(fd);
	fd = open(argv[1], O_RDONLY);
	fill_map(data, fd);
	close(fd);
	if (!data->map.test_map || !*data->map.map || !*data->map.test_map)
		return (printf("what/n"), free_everything(data), error_msg("malloc fail"), 0);
	data->map.collums = ft_strlen(data->map.map[1]);
	player_position(data);
	data->map.collectables = count_collectables(data);
	if (data->map.collectables < 1)
		return (error("No Collectables", data), 0);
	if (!map_valid(data, data->map.test_map))
		return (free_everything(data), 0);
	freemap(data, data->map.test_map);
	return (1);
}
