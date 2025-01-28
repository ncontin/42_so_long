/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   components.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ncontin <ncontin@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/28 11:18:46 by ncontin           #+#    #+#             */
/*   Updated: 2025/01/28 12:39:53 by ncontin          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../so_long.h"

static void	find_component(t_map *map, int y, int x, char component)
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
		{
			map->collectibles++;
		}
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
			find_component(map, y, x, 'P');
			find_component(map, y, x, 'E');
			find_component(map, y, x, 'C');
			x++;
		}
		y++;
	}
}
void	check_result(t_data *data, int door, int collectible, int player)
{
	if (door != 1 || collectible < 1 || player != 1)
	{
		free_data(data);
		ft_putstr_fd("Error\nThe map is invalid\n", 2);
		exit(1);
	}
}
void	check_map_components(t_data *data)
{
	int	y;
	int	x;
	int	door;
	int	collectible;
	int	player;

	door = 0;
	collectible = 0;
	player = 0;
	y = 0;
	while (data->map->grid[y])
	{
		x = 0;
		while (data->map->grid[y][x])
		{
			if (data->map->grid[y][x] == 'E')
				door += 1;
			else if (data->map->grid[y][x] == 'C')
				collectible += 1;
			else if (data->map->grid[y][x] == 'P')
				player += 1;
			x++;
		}
		y++;
	}
	check_result(data, door, collectible, player);
}
