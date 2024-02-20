#include "../so_long.h"

int	window_size(int value)
{
	return (value * 50);
}

int	control(t_data *data)
{
	data->win_w = window_size(data->map.collums);
	data->win_h = window_size(data->map.rows);
	data->win_ptr = mlx_new_window(data->mlx_ptr, data->win_w , data->win_h + 50, "Window 1");
	if (!data->win_ptr)
	{
		data->win_ptr = mlx_new_window(data->mlx_ptr, data->win_h, data->win_w, "Window 2");
		if (!data->win_ptr)
			return (0);
	}
	if (!image_to_window(data))
		return (0);
	mlx_hook(data->win_ptr, KeyRelease, KeyReleaseMask, &on_keypress, data);
	mlx_hook(data->win_ptr, DestroyNotify, StructureNotifyMask, &on_destroy, data);
	//mlx_loop_hook(data->mlx_ptr, update, (void *)data);
	mlx_loop(data->mlx_ptr);
	return (1);
}
