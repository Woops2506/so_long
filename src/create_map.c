/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   create_map.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mareurin <mareurin@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/18 18:33:31 by mareurin          #+#    #+#             */
/*   Updated: 2024/03/25 17:37:48 by mareurin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../so_long.h"

void	fill_map(t_data *data, int fd)
{
	char	*tmp;
	int		c;

	c = 0;
	data->map.map = ft_calloc((data->map.rows + 1), sizeof(char *));
	data->map.test_map = ft_calloc((data->map.rows + 1), sizeof(char *));
	if (!data->map.test_map || !data->map.map)
		error("map malloc failed", data);
	while (c < data->map.rows)
	{
		tmp = get_next_line(fd);
		if (tmp)
		{
			data->map.map[c] = ft_strtrim(tmp, "\n");
			data->map.test_map[c] = ft_strdup(tmp);
			if (!data->map.map[c] || !data->map.test_map[c])
			{
				free(tmp);
				error("failed to map data into array", data);
			}
			free(tmp);
		}
		c++;
	}
}

// free von maps falls error
