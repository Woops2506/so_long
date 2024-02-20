#include "../so_long.h"

void	freevisited(char **visited, t_map *map)
{
	int	c;

	c = 0;
	while (c < map->rows)
	{
		free(visited[c]);
		c++;
	}
	free(visited);
}

void	freemap(t_map *map)
{
	int	c;

	c = 0;
	while (map->map[c])
	{
		free(map->map[c]);
		c++;
	}
	free(map->map);
}

void	freeimg(t_data *data, void *img[])
{
	int	c;

	c = 0;
	while (img[c])
	{
		mlx_destroy_image(data->mlx_ptr, img[c]);
		c++;
	}
}

void	freename(char *name[])
{
	int c;

	c = 0;
	while (name[c])
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
	freemap(&data->map);
	freename(data->img.addres);
	freename(data->img.tr_addr);
	freename(data->player.name);
	freename(data->player.addr);
	freename(data->player.tr_addr);
	freeimg(data, data->img.ptr);
	freeimg(data, data->img.tr);
	freeimg(data, data->player.ptr);
	freeimg(data, data->player.tr);
	mlx_destroy_window(data->mlx_ptr, data->win_ptr);
	mlx_destroy_display(data->mlx_ptr);
	free(data->mlx_ptr);
}
