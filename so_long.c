/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ncontin <ncontin@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/20 13:10:57 by ncontin           #+#    #+#             */
/*   Updated: 2025/02/05 12:46:12 by ncontin          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

static int	handle_keypress(int key, t_data *data)
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

static int	handle_close(t_data *data)
{
	cleanup(data);
	exit(0);
	return (0);
}

static void	init_data(t_data *data)
{
	t_map	*map;

	map = malloc(sizeof(t_map));
	if (!map)
	{
		free(data);
		exit(1);
	}
	data->move_count = 0;
	data->map = map;
	map->tile_size = 32;
	data->map->collectibles = 0;
	data->map->collected = 0;
}

static void	check_args(int argc)
{
	if (argc < 2)
		exit(1);
	if (argc > 2)
	{
		ft_putstr_fd("Error\n", 2);
		ft_putstr_fd("Too many arguments\n", 2);
		exit(1);
	}
}

int	main(int argc, char **argv)
{
	t_data	*data;

	check_args(argc);
	data = malloc(sizeof(t_data));
	if (!data)
		return (1);
	init_data(data);
	read_map(argv[1], data, 0);
	store_grid(argv[1], data);
	validate_map(data);
	open_window(data);
	load_textures(data);
	draw_map(data);
	mlx_hook(data->win_ptr, 2, 1L << 0, handle_keypress, data);
	mlx_hook(data->win_ptr, 17, 0, handle_close, data);
	mlx_loop(data->mlx_ptr);
}
