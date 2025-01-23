/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ncontin <ncontin@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/20 13:10:57 by ncontin           #+#    #+#             */
/*   Updated: 2025/01/23 10:28:09 by ncontin          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"
#include <stdio.h>

void	cleanup(t_data *data)
{
	// mlx_destroy_image(data->mlx_ptr, data->background);
	mlx_clear_window(data->mlx_ptr, data->win_ptr);
	mlx_destroy_window(data->mlx_ptr, data->win_ptr);
	mlx_destroy_display(data->mlx_ptr);
	free(data->mlx_ptr);
}
// void	render_map(t_data *data)
// {
// 	int	x;
// 	int	y;

// 	x = 0;
// 	while (x < WINDOW_WIDTH)
// 	{
// 		y = 0;
// 		while (y < WINDOW_HEIGHT)
// 		{
// 			mlx_pixel_put(data->mlx_ptr, data->win_ptr, x, y, 200);
// 			y++;
// 		}
// 		x++;
// 	}
// }

int	handle_keypress(int keycode, t_data *data)
{
	static int	count = 0;

	if (keycode == W || keycode == A || keycode == S || keycode == D)
	{
		count++;
		ft_printf("move count: %d\n", count);
	}
	if (keycode == ESC)
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

void	read_map(char *arg, t_map *map)
{
	int		fd;
	char	*map_path;
	char	*line;

	map->height = 0;
	map_path = ft_strjoin(MAP_FOLDER, arg);
	if (!map_path)
		return ;
	fd = open(map_path, O_RDONLY);
	if (fd < 0)
	{
		perror("Error opening file");
		return ;
	}
	line = get_next_line(fd);
	map->width = map->tile_size * (ft_strlen(line) - 1);
	while (line)
	{
		ft_printf("%s", line);
		free(line);
		line = get_next_line(fd);
		map->height++;
	}
	map->height = map->height * map->tile_size;
	ft_printf("height: %d, width: %d\n", map->height, map->width);
	free(map_path);
}

void	get_window_size(t_map *map)
{
	(void)map;
	// find width
	return ;
}

int	main(int argc, char **argv)
{
	t_data	data;
	t_map	*map;

	// int		img_height;
	// int		img_width;
	if (argc < 2)
		return (1);
	map = malloc(sizeof(t_map));
	map->tile_size = 32;
	read_map(argv[1], map);
	// img_width = 0;
	// img_height = 0;
	data.mlx_ptr = mlx_init();
	if (!data.mlx_ptr)
		return (1);
	data.win_ptr = mlx_new_window(data.mlx_ptr, map->width, map->height,
			"so_long");
	if (!data.win_ptr)
	{
		free(data.mlx_ptr);
		return (1);
	}
	// data.background = mlx_xpm_file_to_image(data.mlx_ptr,
	// "./assets/Space.xpm",
	// 		&img_width, &img_height);
	// if (!data.background)
	// {
	// 	free(data.mlx_ptr);
	// 	return (1);
	// }
	// mlx_put_image_to_window(data.mlx_ptr, data.win_ptr, data.background, 0,
	// 0);
	// render_map(&data);
	free(map);
	mlx_hook(data.win_ptr, 2, 1L << 0, handle_keypress, &data);
	mlx_hook(data.win_ptr, 17, 0, handle_close, &data);
	mlx_loop(data.mlx_ptr);
	return (0);
}
