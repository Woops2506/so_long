#include "../so_long.h"

int	on_destroy(t_data *data)
{
	freedata(data);
	exit(0);
	return (0);
}

int	on_keypress(int keysym, t_data *data)
{
	(void)data;
	if (keysym == XK_a || keysym == XK_Left)
	{
		if (valid_move(data, 'a'))
		{
			data->steps += 1;
			collecting(data);
			base_img_print(data, 12);
		}
	}
	if (keysym == XK_w || keysym == XK_Up)
	{
		if (valid_move(data, 'w'))
		{
			data->steps += 1;
			collecting(data);
			base_img_print(data, 8);
		}
	}
	if (keysym == XK_d || keysym == XK_Right)
	{
		if (valid_move(data, 'd'))
		{
			data->steps += 1;
			collecting(data);
			base_img_print(data, 4);
		}
	}
	if (keysym == XK_s || keysym == XK_Down)
	{
		if (valid_move(data, 's'))
		{
			data->steps += 1;
			collecting(data);
			base_img_print(data, 0);
		}
	}
	if (keysym == XK_x)
		mlx_clear_window(data->mlx_ptr, data->win_ptr);
	end_game(data);
	if (keysym == XK_Escape)
		on_destroy(data);
	printf("Pressed key: %d\n", keysym);
	return (0);
}
