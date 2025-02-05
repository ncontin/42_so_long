/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   render.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ncontin <ncontin@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/05 12:58:46 by ncontin           #+#    #+#             */
/*   Updated: 2025/02/05 15:40:24 by ncontin          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../so_long.h"

void	load_textures(t_data *data)
{
	int	size;
	int	window_width;
	int	window_height;

	window_width = get_window_width(data->map);
	window_height = get_window_height(data->map);
	size = data->map->tile_size;
	data->textures[BG] = mlx_xpm_file_to_image(data->mlx_ptr,
			"assets/sprites/bg.xpm", &window_width, &window_height);
	data->textures[WALL] = mlx_xpm_file_to_image(data->mlx_ptr,
			"assets/sprites/wall.xpm", &size, &size);
	data->textures[EXIT] = mlx_xpm_file_to_image(data->mlx_ptr,
			"assets/sprites/exit.xpm", &size, &size);
	data->textures[PLAYER] = mlx_xpm_file_to_image(data->mlx_ptr,
			"assets/sprites/player.xpm", &size, &size);
	data->textures[KEY] = mlx_xpm_file_to_image(data->mlx_ptr,
			"assets/sprites/key.xpm", &size, &size);
	if (!data->textures[BG] || !data->textures[WALL] || !data->textures[EXIT]
		|| !data->textures[PLAYER] || !data->textures[KEY])
	{
		ft_putstr_fd("Error\n", 2);
		ft_putstr_fd("One or more textures failed to load\n", 2);
		cleanup(data);
		exit(1);
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
