/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mareurin <mareurin@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/18 18:33:19 by mareurin          #+#    #+#             */
/*   Updated: 2024/03/25 18:21:39 by mareurin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../so_long.h"

void	visited_to_terminal(char **visited)
{
	int	c;

	c = 0;
	if (!visited)
		return ;
	if (!*visited)
		return ;
	while (visited[c])
	{
		printf("%s\n", visited[c]);
		c++;
	}
}

void	map_to_terminal(t_data *data)
{
	int	c;

	c = 0;
	if (!data->map.map)
		return ;
	if (!*data->map.map)
		return ;
	while (data->map.map[c])
	{
		printf("%s\n", data->map.map[c]);
		c++;
	}
}

int	main(int argc, char **argv)
{
	t_data	data;

	if (argc < 2)
	{
		error_msg("please put a map as argument");
		return (0);
	}
	if (!start_check(&data, argv))
	{
		return (0);
	}
	mlx_initialize(&data);
	return (0);
}
