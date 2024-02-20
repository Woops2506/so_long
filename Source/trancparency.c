#include "../so_long.h"

unsigned int	backround(t_data *data, int c, int i)
{
	return (*(unsigned int *)((data->img.addres[3] + (i * data->img.line_len[3]) + (c * data->img.bpp[3] / 8))));
}

unsigned int	get_pixel_img(t_data *data, int c, int i, int n)
{
	return (*(unsigned int *)((data->player.addr[n] + (i * data->player.line_len) + (c * data->player.bpp / 8))));
}

void	put_pixel_img(t_data *data, int c, int i, int n, int color)
{
	char	*d;
	int		x;

	x = backround(data, c, i);
	d = data->player.tr_addr[n] + (i * data->player.line_len + c * (data->player.bpp / 8));
	*(unsigned int *)d = x;
	if (color == (int)0xFF000000)
	{
		return ;
	}
	if (c >= 0 && i >= 0 && c < data->player.width && i < data->player.height)
	{
		d = data->player.tr_addr[n] + (i * data->player.line_len + c * (data->player.bpp / 8));
		*(unsigned int *)d = color;
	}
}

void	transperency(t_data *data, int n)
{
	int		c;
	int		i;

	c = 0;
	data->player.tr[n] = mlx_new_image(data->mlx_ptr, data->player.width, data->player.height);
	data->player.tr_addr[n] = mlx_get_data_addr(data->player.tr[n], &data->player.bpp, &data->player.line_len, &data->player.endian);
	while (c < data->player.width)
	{
		i = 0;
		while (i < data->player.height)
		{
			put_pixel_img(data, c, i, n, get_pixel_img(data, c, i, n));
			i++;
		}
		c++;
	}
}

unsigned int	get_pixel_img_img(t_data *data, int c, int i, int n)
{
	return (*(unsigned int *)((data->img.addres[n] + (i * data->img.line_len[n]) + (c * data->img.bpp[n] / 8))));
}

void	put_pixel_img_img(t_data *data, int c, int i, int n, int color)
{
	char	*d;
	int		x;

	x = backround(data, c, i);
	d = data->img.tr_addr[n] + (i * data->img.line_len[n] + c * (data->img.bpp[n] / 8));
	*(unsigned int *)d = x;
	if (color == (int)0xFF000000)
	{
		return ;
	}
	if (c >= 0 && i >= 0 && c < data->img.width && i < data->img.height)
	{
		*(unsigned int *)d = color;
	}
}

void	transperency_img(t_data *data, int n)
{
	int		c;
	int		i;

	c = 0;
	data->img.tr[n] = mlx_new_image(data->mlx_ptr, data->img.width, data->img.height);
	data->img.tr_addr[n] = mlx_get_data_addr(data->img.tr[n], &data->img.bpp[n], &data->img.line_len[n], &data->img.endian[n]);
	while (c <= data->img.width)
	{
		i = 0;
		while (i <= data->img.height)
		{
			put_pixel_img_img(data, c, i, n, get_pixel_img_img(data, c, i, n));
			i++;
		}
		c++;
	}
}
