/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   what_wall.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mareurin <mareurin@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/21 16:55:33 by mareurin          #+#    #+#             */
/*   Updated: 2024/03/25 18:35:36 by mareurin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../so_long.h"

int	check_for_wall(char c)
{
	if (c == '1')
		return (1);
	return (0);
}

int	check_border(t_data *data)
{
	if (data->currentimg.c == 0)
	{
		if (check_for_wall(data->map.map[data->currentimg.c][data->currentimg.i + 1]))
			return (11);
		return (16);
	}
	if (data->currentimg.c == data->map.rows - 1)
	{
		if (check_for_wall(data->map.map[data->currentimg.c - 1][data->currentimg.i]))
			return (13);
		return (12);
	}
	if (data->currentimg.i == 0)
	{
		if (check_for_wall(data->map.map[data->currentimg.c + 1][data->currentimg.i]))
			return (14);
		return (12);
	}
	if (check_for_wall(data->map.map[data->currentimg.c][data->currentimg.i - 1]))
			return (7);
	return (17);
}

int	place_border(t_data *data)
{
	if (data->currentimg.c == 0 && data->currentimg.i == 0)
		return (10);
	if (data->currentimg.c == 0 && data->currentimg.i == data->map.collums - 1)
		return (6);
	if (data->currentimg.c == data->map.rows - 2 && data->currentimg.i == 0)
		return (9);
	if (data->currentimg.c == data->map.rows - 2 && data->currentimg.i == data->map.collums - 1)
		return (5);
	return(check_border(data));
}

int	explore_walls(char c)
{
	if (c == '1')
		return (1);
	return (0);
}

int	what_wall(t_data *data)
{
	int		checking_top;
	int		checking_bot;
	int		checking_left;
	int		checking_right;

	data->map.testcounter = 0;
	checking_top = explore_walls(data->map.map[data->currentimg.c - 1][data->currentimg.i]);
	if (checking_top == 1)
		data->map.testcounter += 1;
	checking_bot = explore_walls(data->map.map[data->currentimg.c + 1][data->currentimg.i]);
	if (checking_bot == 1)
		data->map.testcounter += 2;
	checking_left = explore_walls(data->map.map[data->currentimg.c][data->currentimg.i - 1]);
	if (checking_left == 1)
		data->map.testcounter += 4;
	checking_right = explore_walls(data->map.map[data->currentimg.c][data->currentimg.i + 1]);
	if (checking_right == 1)
		data->map.testcounter += 8;
	return (data->map.testcounter);
}
