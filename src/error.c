/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   error.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mareurin <mareurin@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/18 18:33:23 by mareurin          #+#    #+#             */
/*   Updated: 2024/03/25 17:37:02 by mareurin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../so_long.h"

void	error_msg(char *msg)
{
	ft_printf("ERROR:\n");
	ft_printf("%s\n", msg);
}

void	error(char *msg, t_data *data)
{
	free_everything(data);
	ft_printf("ERROR:\n");
	ft_printf("%s\n", msg);
	exit (1);
}
