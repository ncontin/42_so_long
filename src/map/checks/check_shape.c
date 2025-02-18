/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_shape.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ncontin <ncontin@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/28 11:51:12 by ncontin           #+#    #+#             */
/*   Updated: 2025/02/18 10:40:47 by ncontin          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../../so_long.h"

static void	handle_error(t_data *data)
{
	ft_putstr_fd("Error\n", 2);
	ft_putstr_fd("The map must be rectangular\n", 2);
	free_data(data);
	exit(1);
}

void	check_map_shape(t_data *data)
{
	int	y;
	int	len;

	y = 0;
	len = 0;
	while (data->map->grid[y])
	{
		len = 0;
		while (data->map->grid[y][len])
		{
			if (data->map->grid[y][len] == '\n')
				break ;
			len++;
		}
		if (len != data->map->width)
			handle_error(data);
		y++;
	}
}
