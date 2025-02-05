/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   draw_textures.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ncontin <ncontin@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/24 16:18:57 by ncontin           #+#    #+#             */
/*   Updated: 2025/02/05 12:29:54 by ncontin          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../so_long.h"

static void	get_component_pos(t_map *map, int y, int x, char component)
{
	if (map->grid[y][x] == component)
	{
		if (component == 'P')
		{
			map->player_x = x;
			map->player_y = y;
		}
		else if (component == 'E')
		{
			map->exit_x = x;
			map->exit_y = y;
		}
		else if (component == 'C')
			map->collectibles++;
	}
}

void	find_components(t_map *map)
{
	int	y;
	int	x;

	y = 0;
	while (map->grid[y])
	{
		x = 0;
		while (map->grid[y][x])
		{
			get_component_pos(map, y, x, 'P');
			get_component_pos(map, y, x, 'E');
			get_component_pos(map, y, x, 'C');
			x++;
		}
		y++;
	}
}

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
