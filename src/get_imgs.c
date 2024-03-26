/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_imgs.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mareurin <mareurin@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/21 17:36:23 by mareurin          #+#    #+#             */
/*   Updated: 2024/03/25 18:05:03 by mareurin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../so_long.h"

void	image_alloc(t_data *data)
{
	int	c;

	c = 0;
	while (c < 18)
	{
		data->img.ptr[c] = mlx_xpm_file_to_image(data->mlx_ptr,
				data->img.path[c], &data->img.width, &data->img.height);
		if (!data->img.ptr[c])
			printf("Oh Fuck\n");
		c++;
	}
}

void	get_imgs(t_data *data)
{
	data->img.path[0] = "./assets/walls/sp.xpm";
	data->img.path[1] = "./assets/walls/dead_end_down.xpm";
	data->img.path[2] = "./assets/walls/dead_end_up.xpm";
	data->img.path[3] = "./assets/walls/middle_single.xpm";
	data->img.path[4] = "./assets/walls/dead_end_right.xpm";
	data->img.path[5] = "./assets/walls/bot_right_corner.xpm";
	data->img.path[6] = "./assets/walls/top_right_corner.xpm";
	data->img.path[7] = "./assets/walls/T_left.xpm";
	data->img.path[8] = "./assets/walls/dead_end_left.xpm";
	data->img.path[9] = "./assets/walls/bot_left_corner.xpm";
	data->img.path[10] = "./assets/walls/top_left_corner.xpm";
	data->img.path[11] = "./assets/walls/T_right.xpm";
	data->img.path[12] = "./assets/walls/top_bot_border.xpm";
	data->img.path[13] = "./assets/walls/T_up.xpm";
	data->img.path[14] = "./assets/walls/T_down.xpm";
	data->img.path[15] = "./assets/walls/xr.xpm";
	data->img.path[16] = "./assets/walls/left_border.xpm";
	data->img.path[17] = "./assets/walls/right_border.xpm";
	image_alloc(data);
}
