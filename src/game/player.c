/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   player.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ncontin <ncontin@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/24 13:23:34 by ncontin           #+#    #+#             */
/*   Updated: 2025/02/05 13:02:09 by ncontin          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../so_long.h"

void	move_player_left(int key, t_data *data)
{
	int	x;
	int	y;
	int	size;

	if (key == A)
	{
		x = data->map->player_x;
		y = data->map->player_y;
		size = data->map->tile_size;
		if (data->map->grid[y][x - 1] != '1')
		{
			data->move_count++;
			ft_printf("move count: %d\n", data->move_count);
			data->map->player_x--;
			mlx_put_image_to_window(data->mlx_ptr, data->win_ptr,
				data->textures[PLAYER], (x - 1) * size, y * size);
			if (data->map->grid[y][x] == 'E')
				mlx_put_image_to_window(data->mlx_ptr, data->win_ptr,
					data->textures[EXIT], x * size, y * size);
			else
				mlx_put_image_to_window(data->mlx_ptr, data->win_ptr,
					data->textures[BG], x * size, y * size);
		}
	}
}

void	move_player_up(int key, t_data *data)
{
	int	x;
	int	y;
	int	size;

	if (key == W)
	{
		x = data->map->player_x;
		y = data->map->player_y;
		size = data->map->tile_size;
		if (data->map->grid[y - 1][x] != '1')
		{
			data->move_count++;
			ft_printf("move count: %d\n", data->move_count);
			data->map->player_y--;
			mlx_put_image_to_window(data->mlx_ptr, data->win_ptr,
				data->textures[PLAYER], x * size, (y - 1) * size);
			if (data->map->grid[y][x] == 'E')
				mlx_put_image_to_window(data->mlx_ptr, data->win_ptr,
					data->textures[EXIT], x * size, y * size);
			else
				mlx_put_image_to_window(data->mlx_ptr, data->win_ptr,
					data->textures[BG], x * size, y * size);
		}
	}
}

void	move_player_right(int key, t_data *data)
{
	int	x;
	int	y;
	int	size;

	if (key == D)
	{
		x = data->map->player_x;
		y = data->map->player_y;
		size = data->map->tile_size;
		if (data->map->grid[y][x + 1] != '1')
		{
			data->move_count++;
			ft_printf("move count: %d\n", data->move_count);
			data->map->player_x++;
			mlx_put_image_to_window(data->mlx_ptr, data->win_ptr,
				data->textures[PLAYER], (x + 1) * size, y * size);
			if (data->map->grid[y][x] == 'E')
				mlx_put_image_to_window(data->mlx_ptr, data->win_ptr,
					data->textures[EXIT], x * size, y * size);
			else
				mlx_put_image_to_window(data->mlx_ptr, data->win_ptr,
					data->textures[BG], x * size, y * size);
		}
	}
}

void	move_player_down(int key, t_data *data)
{
	int	x;
	int	y;
	int	size;

	if (key == S)
	{
		x = data->map->player_x;
		y = data->map->player_y;
		size = data->map->tile_size;
		if (data->map->grid[y + 1][x] != '1')
		{
			data->move_count++;
			ft_printf("move count: %d\n", data->move_count);
			data->map->player_y++;
			mlx_put_image_to_window(data->mlx_ptr, data->win_ptr,
				data->textures[PLAYER], x * size, (y + 1) * size);
			if (data->map->grid[y][x] == 'E')
				mlx_put_image_to_window(data->mlx_ptr, data->win_ptr,
					data->textures[EXIT], x * size, y * size);
			else
				mlx_put_image_to_window(data->mlx_ptr, data->win_ptr,
					data->textures[BG], x * size, y * size);
		}
	}
}
