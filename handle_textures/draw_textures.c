/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   draw_textures.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ncontin <ncontin@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/24 16:18:57 by ncontin           #+#    #+#             */
/*   Updated: 2025/01/29 17:12:19 by ncontin          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../so_long.h"

static void	draw_wall_bg_exit(t_data *data, int y, int x, char c)
{
	if (!data || !data->mlx_ptr || !data->win_ptr)
		return ;
	if (!data->textures[0] || !data->textures[1] || !data->textures[2]
		|| !data->textures[3] || !data->textures[4])
	{
		ft_putstr_fd("Error\nOne or more textures failed to load\n", 2);
		return ;
	}
	if (c == '1')
	{
		mlx_put_image_to_window(data->mlx_ptr, data->win_ptr, data->textures[1],
			x * data->map->tile_size, y * data->map->tile_size);
	}
	if (c == '0')
	{
		mlx_put_image_to_window(data->mlx_ptr, data->win_ptr, data->textures[0],
			x * data->map->tile_size, y * data->map->tile_size);
	}
	if (c == 'E')
	{
		mlx_put_image_to_window(data->mlx_ptr, data->win_ptr, data->textures[2],
			x * data->map->tile_size, y * data->map->tile_size);
		data->map->exit_x = x;
		data->map->exit_y = y;
	}
}

static void	draw_player_key(t_data *data, int y, int x, char c)
{
	if (!data || !data->mlx_ptr || !data->win_ptr)
		return ;
	if (!data->textures[0] || !data->textures[1] || !data->textures[2]
		|| !data->textures[3] || !data->textures[4])
	{
		ft_putstr_fd("Error\nOne or more textures failed to load\n", 2);
		return ;
	}
	if (c == 'P')
	{
		mlx_put_image_to_window(data->mlx_ptr, data->win_ptr, data->textures[3],
			x * data->map->tile_size, y * data->map->tile_size);
		data->map->player_x = x;
		data->map->player_y = y;
	}
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

	if (!data || !data->mlx_ptr || !data->win_ptr)
		return ;
	if (!data->textures[0] || !data->textures[1] || !data->textures[2]
		|| !data->textures[3] || !data->textures[4])
	{
		ft_putstr_fd("Error\nOne or more textures failed to load\n", 2);
		return ;
	}
	grid = data->map->grid;
	y = 0;
	x = 0;
	while (grid[y])
	{
		x = 0;
		while (grid[y][x])
		{
			draw_wall_bg_exit(data, y, x, grid[y][x]);
			draw_player_key(data, y, x, grid[y][x]);
			x++;
		}
		y++;
	}
}
