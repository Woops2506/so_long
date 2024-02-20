#include "../so_long.h"

void	image_put(t_data *data, void *img_ptr)
{
	mlx_put_image_to_window(data->mlx_ptr, data->win_ptr, img_ptr,
		data->currentimg.i * 50, data->currentimg.c * 50);
}

int	base_img_print(t_data *data, int i)
{
	char	*st;
	int		frame;

	st = ft_itoa(data->steps);
	st = ft_strjoin("STEPS:", st);
	data->currentimg.c = 0;
	data->currentimg.i = 0;
	frame = 0;
	mlx_clear_window(data->mlx_ptr, data->win_ptr);
	while (data->map.map[data->currentimg.c])
	{
		data->currentimg.i = 0;
		while (data->map.map[data->currentimg.c][data->currentimg.i])
		{
			if (data->map.map[data->currentimg.c][data->currentimg.i] == '1')
				image_put(data, data->img.tr[2]);
			else if (data->map.map[data->currentimg.c][data->currentimg.i] == '0' || data->map.map[data->currentimg.c][data->currentimg.i] == 'P')
				image_put(data, data->img.ptr[3]);
			else if (data->map.map[data->currentimg.c][data->currentimg.i] == 'C')
				image_put(data, data->img.tr[0]);
			else if (data->map.map[data->currentimg.c][data->currentimg.i] == 'E' && data->map.collectables == 0)
				image_put(data, data->img.ptr[1]);
			else if (data->map.map[data->currentimg.c][data->currentimg.i] == 'E' && data->map.collectables != 0)
				image_put(data, data->img.ptr[3]);
			data->currentimg.i++;
		}
		data->currentimg.c++;
	}
	data->currentimg.i = 0;
	while (data->currentimg.i < data->win_w / 50)
	{
		image_put(data, data->img.ptr[3]);
		data->currentimg.i++;
	}
	mlx_string_put(data->mlx_ptr, data->win_ptr, 0, data->currentimg.c * 50 + 25, (int)0x000000, st);
	while (frame < 4)
		frame += frames(data, i + frame, frame);
	return (1);
}

int	frames(t_data *data, int i, int frame)
{
	printf("%i\n", i);
	if (frame == 0 && i % 4 == 0)
		mlx_put_image_to_window(data->mlx_ptr, data->win_ptr, data->player.tr[i], data->map.player.i * 50 + 12, data->map.player.c * 50);
	if (frame == 1 && i % 4 == 25)
		mlx_put_image_to_window(data->mlx_ptr, data->win_ptr, data->player.tr[i], data->map.player.i * 50 + 12, data->map.player.c * 50);
	if (frame == 2 && i % 4 == 5)
		mlx_put_image_to_window(data->mlx_ptr, data->win_ptr, data->player.tr[i], data->map.player.i * 50 + 12, data->map.player.c * 50);
	if (frame == 3 && i % 4 == 75)
		mlx_put_image_to_window(data->mlx_ptr, data->win_ptr, data->player.tr[i], data->map.player.i * 50 + 12, data->map.player.c * 50);
	return (1);
}

int	animation(t_data *data)
{
	int	c;

	c = 0;
	data->player.width = 50;
	data->player.height = 50;
	while (c <= 15)
	{
		data->player.name[c] = path(c);
		if (!data->player.name[c])
			return (0);
		data->player.ptr[c] = mlx_xpm_file_to_image(data->mlx_ptr, data->player.name[c], &data->player.width, &data->player.height);
		if (!data->player.ptr[c])
			return (0);
		data->player.addr[c] = mlx_get_data_addr(data->player.ptr[c], &data->player.bpp, &data->player.line_len, &data->player.endian);
		transperency(data, c);
		c++;
	}
	return (1);
}

int	image_to_window(t_data *data)
{
	data->img.width = 50;
	data->img.height = 50;
	data->currentimg.c = 0;
	data->currentimg.i = 0;
	data->img.name[0] = "./assets/Golden_Pumpkin.xpm";
	data->img.name[1] = "./assets/Staircase.xpm";
	data->img.name[2] = "./assets/Prismatic_Shard.xpm";
	data->img.name[3] = "./assets/Cartoon_grass_50.xpm";
	data->img.ptr[0] = mlx_xpm_file_to_image(data->mlx_ptr, data->img.name[0], &data->img.width, &data->img.height);
	if (!data->img.ptr[0])
		return (0);
	data->img.addres[0] = mlx_get_data_addr(data->img.ptr[0], &data->img.bpp[0], &data->img.line_len[0], &data->img.endian[0]);
	if (!data->img.addres[0])
		return (0);
	data->img.ptr[1] = mlx_xpm_file_to_image(data->mlx_ptr, data->img.name[1], &data->img.width, &data->img.height);
	if (!data->img.ptr[1])
		return (0);
	data->img.ptr[3] = mlx_xpm_file_to_image(data->mlx_ptr, data->img.name[3], &data->img.width, &data->img.height);
	if (!data->img.ptr[3])
		return (0);
	data->img.addres[3] = mlx_get_data_addr(data->img.ptr[3], &data->img.bpp[3], &data->img.line_len[3], &data->img.endian[3]);
	if (!data->img.addres[3])
		return (0);
	data->img.ptr[2] = mlx_xpm_file_to_image(data->mlx_ptr, data->img.name[2], &data->img.width, &data->img.height);
	if (!data->img.ptr[2])
		return (0);
	data->img.addres[2] = mlx_get_data_addr(data->img.ptr[2], &data->img.bpp[2], &data->img.line_len[2], &data->img.endian[2]);
	if (!data->img.addres[2])
		return (0);
	transperency_img(data, 0);
	if (!data->img.tr[0])
		return (0);
	transperency_img(data, 2);
	if (!data->img.tr[2])
		return (0);
	if (!animation(data))
		return (0);
	base_img_print(data, 0);
	return (1);
}
