/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ncontin <ncontin@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/20 13:10:57 by ncontin           #+#    #+#             */
/*   Updated: 2025/01/24 17:12:47 by ncontin          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void	collect_keys(t_data *data)
{
	int	x;
	int	y;

	x = data->map->player_x;
	y = data->map->player_y;
	if (data->map->grid[y][x] == 'C')
		data->map->collectibles--;
	if (data->map->collectibles == 0)
		data->map->collected = 1;
	ft_printf("%d\n", data->map->collected);
}

void	end_game(t_data *data)
{
	int	x;
	int	y;

	x = data->map->player_x;
	y = data->map->player_y;
	if (data->map->grid[y][x] == 'E' && data->map->collected == 1)
	{
		cleanup(data);
		exit(0);
	}
}

int	handle_keypress(int key, t_data *data)
{
	move_player_left(key, data);
	move_player_up(key, data);
	move_player_right(key, data);
	move_player_down(key, data);
	collect_keys(data);
	end_game(data);
	if (key == ESC)
	{
		cleanup(data);
		exit(0);
	}
	return (0);
}

int	handle_close(t_data *data)
{
	cleanup(data);
	exit(0);
	return (0);
}

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

int	main(int argc, char **argv)
{
	t_data	*data;
	t_map	*map;

	if (argc < 2)
		return (1);
	map = malloc(sizeof(t_map));
	if (!map)
		return (1);
	data = malloc(sizeof(t_data));
	if (!data)
	{
		free(map);
		return (1);
	}
	data->move_count = 0;
	data->map = map;
	map->tile_size = 32;
	data->map->collectibles = 0;
	data->map->collected = 0;
	read_map(argv[1], data);
	store_grid(argv[1], data);
	data->mlx_ptr = mlx_init();
	if (!data->mlx_ptr)
		return (1);
	data->win_ptr = mlx_new_window(data->mlx_ptr, get_window_width(map),
			get_window_height(map), "so_long");
	if (!data->win_ptr)
	{
		free(data->mlx_ptr);
		return (1);
	}
	load_textures(data);
	draw_map(data);
	mlx_hook(data->win_ptr, 2, 1L << 0, handle_keypress, data);
	mlx_hook(data->win_ptr, 17, 0, handle_close, data);
	mlx_loop(data->mlx_ptr);
	// free(map);
	return (0);
}
