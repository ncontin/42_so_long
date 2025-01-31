/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   draw_textures.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ncontin <ncontin@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/24 16:18:57 by ncontin           #+#    #+#             */
/*   Updated: 2025/01/31 16:08:00 by ncontin          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../so_long.h"

static void	draw_components(t_data *data, int y, int x, char c)
{
	if (c == '1')
		mlx_put_image_to_window(data->mlx_ptr, data->win_ptr, data->textures[1],
			x * data->map->tile_size, y * data->map->tile_size);
	if (c == '0')
		mlx_put_image_to_window(data->mlx_ptr, data->win_ptr, data->textures[0],
			x * data->map->tile_size, y * data->map->tile_size);
	if (c == 'E')
		mlx_put_image_to_window(data->mlx_ptr, data->win_ptr, data->textures[2],
			x * data->map->tile_size, y * data->map->tile_size);
	if (c == 'P')
		mlx_put_image_to_window(data->mlx_ptr, data->win_ptr, data->textures[3],
			x * data->map->tile_size, y * data->map->tile_size);
	if (c == 'C')
		mlx_put_image_to_window(data->mlx_ptr, data->win_ptr, data->textures[4],
			x * data->map->tile_size, y * data->map->tile_size);
}

void	draw_map(t_data *data)
{
	int		y;
	int		x;
	char	**grid;

	grid = data->map->grid;
	y = 0;
	find_components(data->map);
	while (grid[y])
	{
		x = 0;
		while (grid[y][x])
		{
			draw_components(data, y, x, grid[y][x]);
			x++;
		}
		y++;
	}
}
