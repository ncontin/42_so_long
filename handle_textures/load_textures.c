/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   load_textures.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ncontin <ncontin@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/28 17:02:40 by ncontin           #+#    #+#             */
/*   Updated: 2025/01/28 17:02:51 by ncontin          ###   ########.fr       */
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
}
