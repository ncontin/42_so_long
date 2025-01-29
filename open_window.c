/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   open_window.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ncontin <ncontin@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/29 11:29:53 by ncontin           #+#    #+#             */
/*   Updated: 2025/01/29 11:30:47 by ncontin          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

int	get_window_width(t_map *map)
{
	int	window_width;

	window_width = map->width * map->tile_size;
	return (window_width);
}

int	get_window_height(t_map *map)
{
	int	window_height;

	window_height = map->height * map->tile_size;
	return (window_height);
}

void	open_window(t_data *data)
{
	data->mlx_ptr = mlx_init();
	if (!data->mlx_ptr)
		return ;
	data->win_ptr = mlx_new_window(data->mlx_ptr, get_window_width(data->map),
			get_window_height(data->map), "so_long");
	if (!data->win_ptr)
	{
		free(data->mlx_ptr);
		return ;
	}
}
