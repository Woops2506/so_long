/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   mlx_init.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mareurin <mareurin@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/19 13:47:24 by mareurin          #+#    #+#             */
/*   Updated: 2024/03/25 18:22:20 by mareurin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../so_long.h"

int	destruction(t_data *data)
{
	mlx_destroy_window(data->mlx_ptr, data->win_ptr);
	mlx_destroy_display(data->mlx_ptr);
	free(data->mlx_ptr);
	exit(0);
}

int	escape(int key, t_data *data)
{
	if (key == XK_Escape)
		destruction(data);
	return (0);
}

int	mlx_initialize(t_data *data)
{
	data->mlx_ptr = mlx_init();
	data->win_ptr = mlx_new_window(data->mlx_ptr, 2560, 1440, "Woops");
	get_imgs(data);
	test_stuff(data);
	test_walls(data);
	mlx_key_hook(data->win_ptr, &escape, data);
	mlx_hook(data->win_ptr, DestroyNotify, 1L<<17, &destruction, data);
	mlx_loop(data->mlx_ptr);
	return (0);
}
