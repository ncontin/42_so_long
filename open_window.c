/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   open_window.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ncontin <ncontin@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/29 11:29:53 by ncontin           #+#    #+#             */
/*   Updated: 2025/02/03 11:51:31 by ncontin          ###   ########.fr       */
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
	{
		free_data(data);
		ft_putstr_fd("Error\n", 2);
		ft_putstr_fd("MLX initialization failed\n", 2);
		exit(1);
	}
	data->win_ptr = mlx_new_window(data->mlx_ptr, get_window_width(data->map),
			get_window_height(data->map), "so_long");
	if (!data->win_ptr)
	{
		mlx_destroy_display(data->mlx_ptr);
		free(data->mlx_ptr);
		free_data(data);
		ft_putstr_fd("Error\n", 2);
		ft_putstr_fd("MLX new window failed\n", 2);
		exit(1);
	}
}
