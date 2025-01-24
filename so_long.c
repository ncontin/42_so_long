/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ncontin <ncontin@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/20 13:10:57 by ncontin           #+#    #+#             */
/*   Updated: 2025/01/24 13:29:19 by ncontin          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

int	handle_keypress(int key, t_data *data)
{
	move_player_left(key, data);
	move_player_up(key, data);
	move_player_right(key, data);
	move_player_down(key, data);
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

void	load_textures(t_data *data)
{
	int	size;
	int	window_width;
	int	window_height;

	window_width = get_window_width(data->map);
	window_height = get_window_height(data->map);
	size = data->map->tile_size;
	data->textures[0] = mlx_xpm_file_to_image(data->mlx_ptr, "assets/bg.xpm",
			&window_width, &window_height);
	data->textures[1] = mlx_xpm_file_to_image(data->mlx_ptr, "assets/wall.xpm",
			&size, &size);
	data->textures[2] = mlx_xpm_file_to_image(data->mlx_ptr, "assets/exit.xpm",
			&size, &size);
	data->textures[3] = mlx_xpm_file_to_image(data->mlx_ptr,
			"assets/player.xpm", &size, &size);
	data->textures[4] = mlx_xpm_file_to_image(data->mlx_ptr, "assets/key.xpm",
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
void	draw_bg(t_data *data)
{
	mlx_put_image_to_window(data->mlx_ptr, data->win_ptr, data->textures[0], 0,
		0);
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
	mlx_clear_window(data->mlx_ptr, data->win_ptr);
	draw_bg(data);
	while (grid[y])
	{
		x = 0;
		while (grid[y][x])
		{
			draw_wall(data, y, x, grid[y][x]);
			draw_exit(data, y, x, grid[y][x]);
			draw_player(data, y, x, grid[y][x]);
			draw_key(data, y, x, grid[y][x]);
			x++;
		}
		y++;
	}
	mlx_do_sync(data->mlx_ptr);
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
	read_map(argv[1], map);
	store_grid(argv[1], map);
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
	free(map);
	return (0);
}
