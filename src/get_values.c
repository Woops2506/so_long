/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_values.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mareurin <mareurin@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/18 18:33:33 by mareurin          #+#    #+#             */
/*   Updated: 2024/03/25 17:38:57 by mareurin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../so_long.h"

int	window_size(int value)
{
	return (value * 50);
}

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

int	count_collectables(t_data *data)
{
	int	co;
	int	c;
	int	i;

	c = 0;
	co = 0;
	while (data->map.map[c])
	{
		i = 0;
		while (data->map.map[c][i])
		{
			if (data->map.map[c][i] == 'C')
				co++;
			i++;
		}
		c++;
	}
	return (co);
}

void	player_position(t_data *data)
{
	int	c;
	int	i;

	c = 0;
	while (data->map.map[c])
	{
		i = 0;
		while (data->map.map[c][i])
		{
			if (data->map.map[c][i] == 'P')
			{
				data->map.player.c = c;
				data->map.player.i = i;
				data->map.test_map[c][i] = 'V';
				return ;
			}
			i++;
		}
		c++;
	}
}
