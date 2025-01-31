/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   load_textures.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ncontin <ncontin@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/28 17:02:40 by ncontin           #+#    #+#             */
/*   Updated: 2025/01/31 16:05:01 by ncontin          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../so_long.h"

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
	if (!data->textures[BG] || !data->textures[WALL] || !data->textures[EXIT]
		|| !data->textures[PLAYER] || !data->textures[KEY])
	{
		cleanup(data);
		ft_putstr_fd("Error\n", 2);
		ft_putstr_fd("One or more textures failed to load\n", 2);
		exit(1);
	}
}
