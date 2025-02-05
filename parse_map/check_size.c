/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_map_size.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ncontin <ncontin@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/05 11:38:59 by ncontin           #+#    #+#             */
/*   Updated: 2025/02/05 11:54:31 by ncontin          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../so_long.h"

void	check_map_size(t_data *data)
{
	if ((data->map->width * data->map->tile_size) > 1920)
	{
		{
			free_data(data);
			ft_putstr_fd("Error\n", 2);
			ft_putstr_fd("Map is too wide\n", 2);
			exit(1);
		}
	}
	if ((data->map->height * data->map->tile_size) > 1024)
	{
		free_data(data);
		ft_putstr_fd("Error\n", 2);
		ft_putstr_fd("Map is too high\n", 2);
		exit(1);
	}
}
