/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ncontin <ncontin@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/20 13:10:57 by ncontin           #+#    #+#             */
/*   Updated: 2025/01/27 12:36:16 by ncontin          ###   ########.fr       */
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
	{
		data->map->collectibles--;
		data->map->grid[y][x] = '0';
	}
	if (data->map->collectibles == 0)
		data->map->collected = 1;
}

void	end_game(t_data *data)
{
	int	x;
	int	y;

	x = data->map->player_x;
	y = data->map->player_y;
	if (data->map->grid[y][x] == 'E' && data->map->collected == 1)
	{
		ft_printf("Congratulations, you finished the game with %d moves\n",
			data->move_count);
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

void	init_data(t_data *data)
{
	t_map	*map;

	map = malloc(sizeof(t_map));
	if (!map)
	{
		free(data);
		return ;
	}
	data->move_count = 0;
	data->map = map;
	map->tile_size = 32;
	data->map->collectibles = 0;
	data->map->collected = 0;
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

int	main(int argc, char **argv)
{
	t_data	*data;

	if (argc < 2)
		return (1);
	data = malloc(sizeof(t_data));
	if (!data)
		return (1);
	init_data(data);
	read_map(argv[1], data);
	store_grid(argv[1], data);
	validate_map(data);
	open_window(data);
	load_textures(data);
	draw_map(data);
	mlx_hook(data->win_ptr, 2, 1L << 0, handle_keypress, data);
	mlx_hook(data->win_ptr, 17, 0, handle_close, data);
	mlx_loop(data->mlx_ptr);
	return (0);
}
