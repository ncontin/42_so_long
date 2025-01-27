/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   draw.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ncontin <ncontin@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/24 16:18:57 by ncontin           #+#    #+#             */
/*   Updated: 2025/01/27 18:24:34 by ncontin          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void	load_textures(t_data *data)
{
	int	size;
	int	window_width;
	int	window_height;

	window_width = get_window_width(data->map);
	window_height = get_window_height(data->map);
	size = data->map->tile_size;
	data->textures[BG] = mlx_xpm_file_to_image(data->mlx_ptr, "assets/bg.xpm",
			&window_width, &window_height);
	data->textures[WALL] = mlx_xpm_file_to_image(data->mlx_ptr,
			"assets/wall.xpm", &size, &size);
	data->textures[EXIT] = mlx_xpm_file_to_image(data->mlx_ptr,
			"assets/exit.xpm", &size, &size);
	data->textures[PLAYER] = mlx_xpm_file_to_image(data->mlx_ptr,
			"assets/player.xpm", &size, &size);
	data->textures[KEY] = mlx_xpm_file_to_image(data->mlx_ptr, "assets/key.xpm",
			&size, &size);
}

void	draw_wall(t_data *data, int y, int x, char c)
{
	if (c == '1')
	{
		mlx_put_image_to_window(data->mlx_ptr, data->win_ptr, data->textures[1],
			x * data->map->tile_size, y * data->map->tile_size);
	}
}

// need fix
void	draw_bg(t_data *data, int y, int x, char c)
{
	if (c == '0')
	{
		mlx_put_image_to_window(data->mlx_ptr, data->win_ptr, data->textures[0],
			x * data->map->tile_size, y * data->map->tile_size);
	}
}
void	draw_exit(t_data *data, int y, int x, char c)
{
	if (c == 'E')
	{
		mlx_put_image_to_window(data->mlx_ptr, data->win_ptr, data->textures[2],
			x * data->map->tile_size, y * data->map->tile_size);
		data->map->exit_x = x;
		data->map->exit_y = y;
	}
}
void	draw_player(t_data *data, int y, int x, char c)
{
	if (c == 'P')
	{
		mlx_put_image_to_window(data->mlx_ptr, data->win_ptr, data->textures[3],
			x * data->map->tile_size, y * data->map->tile_size);
		data->map->player_x = x;
		data->map->player_y = y;
	}
}
void	draw_key(t_data *data, int y, int x, char c)
{
	if (c == 'C')
	{
		data->map->collectibles++;
		mlx_put_image_to_window(data->mlx_ptr, data->win_ptr, data->textures[4],
			x * data->map->tile_size, y * data->map->tile_size);
	}
}

void	draw_map(t_data *data)
{
	int		y;
	int		x;
	char	**grid;

	grid = data->map->grid;
	y = 0;
	x = 0;
	while (grid[y])
	{
		x = 0;
		while (grid[y][x])
		{
			draw_bg(data, y, x, grid[y][x]);
			draw_wall(data, y, x, grid[y][x]);
			draw_exit(data, y, x, grid[y][x]);
			draw_player(data, y, x, grid[y][x]);
			draw_key(data, y, x, grid[y][x]);
			x++;
		}
		y++;
	}
}
