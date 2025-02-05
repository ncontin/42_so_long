/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   finder.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ncontin <ncontin@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/05 13:25:23 by ncontin           #+#    #+#             */
/*   Updated: 2025/02/05 13:25:45 by ncontin          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../so_long.h"

static void	get_component_pos(t_map *map, int y, int x, char component)
{
	if (map->grid[y][x] == component)
	{
		if (component == 'P')
		{
			map->player_x = x;
			map->player_y = y;
		}
		else if (component == 'E')
		{
			map->exit_x = x;
			map->exit_y = y;
		}
		else if (component == 'C')
			map->collectibles++;
	}
}

void	find_components(t_map *map)
{
	int	y;
	int	x;

	y = 0;
	while (map->grid[y])
	{
		x = 0;
		while (map->grid[y][x])
		{
			get_component_pos(map, y, x, 'P');
			get_component_pos(map, y, x, 'E');
			get_component_pos(map, y, x, 'C');
			x++;
		}
		y++;
	}
}
