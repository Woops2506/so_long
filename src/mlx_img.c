/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   mlx_img.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mareurin <mareurin@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/20 17:10:20 by mareurin          #+#    #+#             */
/*   Updated: 2024/03/25 18:36:52 by mareurin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../so_long.h"

void	image_put(t_data *data, void *img_ptr)
{
	mlx_put_image_to_window(data->mlx_ptr, data->win_ptr, img_ptr,
		data->currentimg.i * 100, data->currentimg.c * 100);
}

void	background(t_data *data)
{
	void	*img;
	char	*path;
	int		ja;
	int		noe;

	ja = 1;
	noe = 1;
	path = "./assets/grass.xpm";
	img = mlx_xpm_file_to_image(data->mlx_ptr, path, &ja, &noe);
	mlx_put_image_to_window(data->mlx_ptr, data->win_ptr, img, 0, 0);
}

void	test_stuff(t_data *data)
{
	void	*img;
	char	*path;
	int		width;
	int		height;

	data->currentimg.c = 0;
	path = "./assets/grass.xpm";
	img = mlx_xpm_file_to_image(data->mlx_ptr, path, &width, &height);
	data->currentimg.c = 0;
	while (data->currentimg.c < data->map.rows)
	{
		data->currentimg.i = 0;
		while (data->currentimg.i < data->map.collums)
		{
			image_put(data, img);
			data->currentimg.i++;
		}
		data->currentimg.c++;
	}
}

void	test_walls(t_data *data)
{
	printf("%i , %i\n", data->map.rows, data->map.collums);
	data->currentimg.c = 0;
	while (data->currentimg.c < data->map.rows - 1)
	{
		data->currentimg.i = 0;
		while (data->currentimg.i < data->map.collums)
		{
			printf("Currently at [%i][%i]\n", data->currentimg.c, data->currentimg.i);
			if (data->currentimg.c == 0 || data->currentimg.i == 0
				|| data->currentimg.c == data->map.rows - 1
				|| data->currentimg.i == data->map.collums - 1)
				image_put(data, data->img.ptr[place_border(data)]);
			else if (data->map.map[data->currentimg.c][data->currentimg.i] == '1')
				image_put(data, data->img.ptr[what_wall(data)]);
			data->currentimg.i++;
		}
		data->currentimg.c++;
	}
}
