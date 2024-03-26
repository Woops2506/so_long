/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   freemem.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mareurin <mareurin@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/18 18:33:28 by mareurin          #+#    #+#             */
/*   Updated: 2024/03/20 16:40:00 by mareurin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../so_long.h"

void	freemap(t_data *data, char **map)
{
	int	i;

	i = data->map.rows;
	while (i >= 0)
	{
		free(map[i]);
		i--;
	}
	free(map);
	map = NULL;
}

void	freeimg(t_data *data, void *img[], int n)
{
	int	c;

	c = 0;
	while (c < n)
	{
		if (img[c])
			mlx_destroy_image(data->mlx_ptr, img[c]);
		c++;
	}
}

void	freename(char **name)
{
	int	c;

	c = 0;
	while (*name[c])
	{
		if (!name[c])
			c++;
		else
		{
			free(name[c]);
			c++;
		}
	}
}

void	freedata(t_data *data)
{
	freename(data->player.name);
	freeimg(data, data->img.ptr, 4);
	freeimg(data, data->img.tr, 2);
	freeimg(data, data->player.ptr, 16);
	freeimg(data, data->player.tr, 16);
	mlx_clear_window(data->mlx_ptr, data->win_ptr);
	mlx_destroy_window(data->mlx_ptr, data->win_ptr);
	mlx_destroy_display(data->mlx_ptr);
	free(data->mlx_ptr);
}

void	free_everything(t_data *data)
{
	if (data->map.test_map)
		freemap(data, data->map.test_map);
	if (data->map.map)
		freemap(data, data->map.map);
}
