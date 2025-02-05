/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cleanup.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ncontin <ncontin@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/23 16:43:32 by ncontin           #+#    #+#             */
/*   Updated: 2025/02/05 13:00:53 by ncontin          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../so_long.h"

void	cleanup(t_data *data)
{
	int	i;

	i = 0;
	while (i < 5)
	{
		if (data->textures[i])
			mlx_destroy_image(data->mlx_ptr, data->textures[i]);
		i++;
	}
	mlx_clear_window(data->mlx_ptr, data->win_ptr);
	mlx_destroy_window(data->mlx_ptr, data->win_ptr);
	mlx_destroy_display(data->mlx_ptr);
	free_grid(data->map);
	free(data->mlx_ptr);
	free(data->map);
	free(data);
}

void	free_grid(t_map *map)
{
	int	i;

	i = 0;
	while (map->grid[i])
	{
		free(map->grid[i]);
		i++;
	}
	free(map->grid);
}

void	free_map(t_map *map)
{
	free_grid(map);
	free(map);
}

void	free_data(t_data *data)
{
	free_map(data->map);
	free(data);
}
