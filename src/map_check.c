/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map_check.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mareurin <mareurin@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/18 18:33:37 by mareurin          #+#    #+#             */
/*   Updated: 2024/03/20 17:23:25 by mareurin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../so_long.h"

int	p_e_check(t_data *data)
{
	int	c;
	int	i;
	int	p;
	int	e;

	c = 0;
	i = 0;
	p = 0;
	e = 0;
	while (data->map.map[c])
	{
		while (data->map.map[c][i])
		{
			if (data->map.map[c][i] == 'P')
				p++;
			if (data->map.map[c][i] == 'E')
				e++;
			i++;
		}
		i = 0;
		c++;
	}
	if (p == 1 && e == 1)
		return (1);
	return (0);
}

int	line_check(t_data *data)
{
	size_t	len;
	int		c;

	c = 0;
	len = ft_strlen(data->map.map[c]);
	while (data->map.map[c])
	{
		if (len != ft_strlen(data->map.map[c]))
			return (0);
		c++;
	}
	if (!data->map.map[c])
		return (1);
	return (0);
}

int	wall_check(t_data *data)
{
	int	c;
	int	i;

	c = 0;
	while (c < data->map.rows - 1)
	{
		i = 0;
		while (i < data->map.collums)
		{
			if ((c == 0 || c == (data->map.rows - 1)) || (i == 0
				|| i == (data->map.collums - 1)))
			{
				if (data->map.map[c][i] != '1')
					return (0);
			}
			i++;
		}
		c++;
	}
	return (1);
}
