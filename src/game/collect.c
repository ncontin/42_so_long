/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   collect.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ncontin <ncontin@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/29 11:37:57 by ncontin           #+#    #+#             */
/*   Updated: 2025/02/05 13:02:16 by ncontin          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../so_long.h"

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
