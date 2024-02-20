#include "../so_long.h"

int	valid_move(t_data *data, char c)
{
	if (c == 'w')
	{
		if (data->map.map[data->map.player.c - 1][data->map.player.i] != '1')
		{
			data->map.player.c--;
			return (1);
		}
	}
	if (c == 'a')
	{
		if (data->map.map[data->map.player.c][data->map.player.i - 1] != '1')
		{
			data->map.player.i--;
			return (1);
		}
	}
	if (c == 's')
	{
		if (data->map.map[data->map.player.c + 1][data->map.player.i] != '1')
		{
			data->map.player.c++;
			return (1);
		}
	}
	if (c == 'd')
	{
		if (data->map.map[data->map.player.c][data->map.player.i + 1] != '1')
		{
			data->map.player.i++;
			return (1);
		}
	}
	return (0);
}

void	collecting(t_data *data)
{
	if (data->map.map[data->map.player.c][data->map.player.i] == 'C')
	{
		data->map.map[data->map.player.c][data->map.player.i] = '0';
		data->map.collectables--;
	}
}

void	end_game(t_data *data)
{
	if (data->map.collectables == 0 && data->map.map[data->map.player.c][data->map.player.i] == 'E')
		on_destroy(data);
}
