/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ncontin <ncontin@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/05 12:59:59 by ncontin           #+#    #+#             */
/*   Updated: 2025/02/05 16:50:08 by ncontin          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../so_long.h"

void	init_data(t_data *data)
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
	data->map->height = 0;
	data->map->width = 0;
	map->tile_size = 32;
	data->map->collectibles = 0;
	data->map->collected = 0;
}
